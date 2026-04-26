#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v5(void) {
    volatile processed = 0;
    volatile unsigned char *pe_buffer = NULL;
    if (!pe_buffer) return;
    PIMAGE_DOS_HEADER dos = NULL;
    PIMAGE_NT_HEADERS nt = NULL;
    LPVOID target = NULL;
    ULONG_PTR delta = 0;
    PIMAGE_BASE_RELOCATION reloc = NULL;
    PIMAGE_IMPORT_DESCRIPTOR imp = NULL;
    HMODULE mod = NULL;
    PIMAGE_THUNK_DATA orig = NULL;
    PIMAGE_THUNK_DATA ft = NULL;
    PIMAGE_SECTION_HEADER sect = NULL;
    WORD i = 0;
    int j = 0;
    int count = 0;
    PWORD list = NULL;
    typedef BOOL (WINAPI *DllMain_t)(HMODULE, DWORD, LPVOID);
    DllMain_t entry = NULL;
    int state = 0;
    while (1) {
        switch (state) {
            case 0:
                dos = (PIMAGE_DOS_HEADER)pe_buffer;
                if (dos->e_magic != IMAGE_DOS_SIGNATURE) return;
                state = 1;
                processed=1;
                break;
            case 1:
                nt = (PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew);
                if (nt->Signature != IMAGE_NT_SIGNATURE) return;
                state = 2;
                break;
            case 2:
                target = VirtualAlloc(NULL, nt->OptionalHeader.SizeOfImage, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
                if (!target) return;
                state = 3;
                processed=10;
                break;
            case 3:
                memcpy(target, pe_buffer, nt->OptionalHeader.SizeOfHeaders);
                state = 4;
                processed=2;
                break;
            case 4:
                sect = IMAGE_FIRST_SECTION(nt);
                i = 0;
                state = 5;
                break;
            case 5:
                if (i < nt->FileHeader.NumberOfSections) {
                    state = 6;
                } else {
                    state = 7;
                }
                break;
            case 6:
                memcpy((LPBYTE)target + sect[i].VirtualAddress, pe_buffer + sect[i].PointerToRawData, sect[i].SizeOfRawData);
                i++;
                state = 5;
                break;
            case 7:
                if ((ULONG_PTR)target != nt->OptionalHeader.ImageBase) {
                    delta = (ULONG_PTR)target - nt->OptionalHeader.ImageBase;
                    reloc = (PIMAGE_BASE_RELOCATION)((LPBYTE)target + nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
                    state = 8;
                } else {
                    state = 13;
                }
                break;
            case 8:
                if (reloc->VirtualAddress) {
                    state = 9;
                } else {
                    state = 13;
                }
                break;
            case 9:
                if (reloc->SizeOfBlock >= sizeof(IMAGE_BASE_RELOCATION)) {
                    count = (reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
                    list = (PWORD)((LPBYTE)reloc + sizeof(IMAGE_BASE_RELOCATION));
                    j = 0;
                    state = 10;
                    processed=11;
                } else {
                    state = 12;
                }
                break;
            case 10:
                if (j < count) {
                    state = 11;
                } else {
                    state = 12;
                }
                break;
            case 11:
                if (list[j]) {
                    ULONG_PTR *ptr = (ULONG_PTR *)((LPBYTE)target + reloc->VirtualAddress + (list[j] & 0xFFF));
                    *ptr += delta;
                }
                j++;
                state = 10;
                break;
            case 12:
                reloc = (PIMAGE_BASE_RELOCATION)((LPBYTE)reloc + reloc->SizeOfBlock);
                state = 8;
                break;
            case 13:
                imp = (PIMAGE_IMPORT_DESCRIPTOR)((LPBYTE)target + nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
                state = 14;
                break;
            case 14:
                if (imp->Characteristics) {
                    state = 15;
                } else {
                    state = 20;
                }
                break;
            case 15:
                mod = LoadLibraryA((LPCSTR)target + imp->Name);
                orig = (PIMAGE_THUNK_DATA)((LPBYTE)target + imp->OriginalFirstThunk);
                ft = (PIMAGE_THUNK_DATA)((LPBYTE)target + imp->FirstThunk);
                state = 16;
                break;
            case 16:
                if (orig->u1.AddressOfData) {
                    state = 17;
                } else {
                    state = 19;
                }
                break;
            case 17:
                if (orig->u1.Ordinal & IMAGE_ORDINAL_FLAG) {
                    ft->u1.Function = (ULONG_PTR)GetProcAddress(mod, (LPCSTR)(orig->u1.Ordinal & 0xFFFF));
                } else {
                    PIMAGE_IMPORT_BY_NAME ibn = (PIMAGE_IMPORT_BY_NAME)((LPBYTE)target + orig->u1.AddressOfData);
                    ft->u1.Function = (ULONG_PTR)GetProcAddress(mod, ibn->Name);
                }
                state = 18;
                break;
            case 18:
                orig++;
                ft++;
                state = 16;
                break;
            case 19:
                imp++;
                state = 14;
                break;
            case 20:
                entry = (DllMain_t)((LPBYTE)target + nt->OptionalHeader.AddressOfEntryPoint);
                entry((HMODULE)target, DLL_PROCESS_ATTACH, NULL);
                return;
        }
    }
    return processed;
}