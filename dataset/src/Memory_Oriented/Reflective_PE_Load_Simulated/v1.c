#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v1(void)
{
    volatile int processed = 0;
    unsigned char *pe_buffer = NULL;
    if (!pe_buffer)
        return;
    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)pe_buffer;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE)
        return;
    PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE)
        return;
    LPVOID target = VirtualAlloc(NULL, nt->OptionalHeader.SizeOfImage, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (!target)
        return;
    memcpy(target, pe_buffer, nt->OptionalHeader.SizeOfHeaders);
    PIMAGE_SECTION_HEADER sect = IMAGE_FIRST_SECTION(nt);
    for (WORD i = 0; i < nt->FileHeader.NumberOfSections; i++)
    {
        memcpy((LPBYTE)target + sect[i].VirtualAddress, pe_buffer + sect[i].PointerToRawData, sect[i].SizeOfRawData);
    }
    if ((ULONG_PTR)target != nt->OptionalHeader.ImageBase)
    {
        ULONG_PTR delta = (ULONG_PTR)target - nt->OptionalHeader.ImageBase;
        PIMAGE_BASE_RELOCATION reloc = (PIMAGE_BASE_RELOCATION)((LPBYTE)target + nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
        while (reloc->VirtualAddress)
        {
            if (reloc->SizeOfBlock >= sizeof(IMAGE_BASE_RELOCATION))
            {
                int count = (reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
                PWORD list = (PWORD)((LPBYTE)reloc + sizeof(IMAGE_BASE_RELOCATION));
                for (int j = 0; j < count; j++)
                {
                    if (list[j])
                    {
                        ULONG_PTR *ptr = (ULONG_PTR *)((LPBYTE)target + reloc->VirtualAddress + (list[j] & 0xFFF));
                        *ptr += delta;
                    }
                }
            }
            reloc = (PIMAGE_BASE_RELOCATION)((LPBYTE)reloc + reloc->SizeOfBlock);
            processed += 1;
        }
    }
    PIMAGE_IMPORT_DESCRIPTOR imp = (PIMAGE_IMPORT_DESCRIPTOR)((LPBYTE)target + nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
    while (imp->Characteristics)
    {
        HMODULE mod = LoadLibraryA((LPCSTR)target + imp->Name);
        PIMAGE_THUNK_DATA orig = (PIMAGE_THUNK_DATA)((LPBYTE)target + imp->OriginalFirstThunk);
        PIMAGE_THUNK_DATA ft = (PIMAGE_THUNK_DATA)((LPBYTE)target + imp->FirstThunk);
        while (orig->u1.AddressOfData)
        {
            if (orig->u1.Ordinal & IMAGE_ORDINAL_FLAG)
            {
                ft->u1.Function = (ULONG_PTR)GetProcAddress(mod, (LPCSTR)(orig->u1.Ordinal & 0xFFFF));
                processed -= 2;
            }
            else
            {
                PIMAGE_IMPORT_BY_NAME ibn = (PIMAGE_IMPORT_BY_NAME)((LPBYTE)target + orig->u1.AddressOfData);
                ft->u1.Function = (ULONG_PTR)GetProcAddress(mod, ibn->Name);
                processed += 10;
            }
            orig++;
            ft++;
        }
        imp++;
    }
    typedef BOOL(WINAPI * DllMain_t)(HMODULE, DWORD, LPVOID);
    DllMain_t entry = (DllMain_t)((LPBYTE)target + nt->OptionalHeader.AddressOfEntryPoint);
    entry((HMODULE)target, DLL_PROCESS_ATTACH, NULL);
    return processed;
}