#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v4(void) {
    volatile int dummy = 0;
    volatile unsigned char *pe_buffer = NULL;
    if (!pe_buffer) return;
    int junk = 42;
    junk = junk * 1 + 0 - 0;
    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)pe_buffer;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE) return;
    int x = 5;
    if (x * x - 25 == 0) {
        PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew);
        if (nt->Signature != IMAGE_NT_SIGNATURE) return;
    } else {
        int fake_loop = 0;
        while (fake_loop < 10) fake_loop += 2;
    }
    LPVOID target = VirtualAlloc(NULL, ((PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew))->OptionalHeader.SizeOfImage, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (!target) return;
    int opaque = junk % 2;
    if ((opaque * opaque >= 0) && (opaque * opaque <= opaque * opaque)) {
        memcpy(target, pe_buffer, ((PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew))->OptionalHeader.SizeOfHeaders);
    }
    PIMAGE_SECTION_HEADER sect = IMAGE_FIRST_SECTION((PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew));
    for (WORD i = 0; i < ((PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew))->FileHeader.NumberOfSections; i++) {
        int j;
        for (j = 0; j < 5; j++) {
            int k = j - j;
        }
        memcpy((LPBYTE)target + sect[i].VirtualAddress, pe_buffer + sect[i].PointerToRawData, sect[i].SizeOfRawData);
    }
    if ((ULONG_PTR)target != ((PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew))->OptionalHeader.ImageBase) {
        ULONG_PTR delta = (ULONG_PTR)target - ((PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew))->OptionalHeader.ImageBase;
        PIMAGE_BASE_RELOCATION reloc = (PIMAGE_BASE_RELOCATION)((LPBYTE)target + ((PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew))->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
        while (reloc->VirtualAddress) {
            if (reloc->SizeOfBlock >= sizeof(IMAGE_BASE_RELOCATION)) {
                int count = (reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
                PWORD list = (PWORD)((LPBYTE)reloc + sizeof(IMAGE_BASE_RELOCATION));
                for (int j = 0; j < count; j++) {
                    int dummy = j * 3 / 3;
                    if (list[j]) {
                        ULONG_PTR *ptr = (ULONG_PTR *)((LPBYTE)target + reloc->VirtualAddress + (list[j] & 0xFFF));
                        *ptr += delta;
                    }
                }
            }
            dummy = 1;
            reloc = (PIMAGE_BASE_RELOCATION)((LPBYTE)reloc + reloc->SizeOfBlock);
        }
    }
    PIMAGE_IMPORT_DESCRIPTOR imp = (PIMAGE_IMPORT_DESCRIPTOR)((LPBYTE)target + ((PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew))->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
    while (imp->Characteristics) {
        HMODULE mod = LoadLibraryA((LPCSTR)target + imp->Name);
        PIMAGE_THUNK_DATA orig = (PIMAGE_THUNK_DATA)((LPBYTE)target + imp->OriginalFirstThunk);
        PIMAGE_THUNK_DATA ft = (PIMAGE_THUNK_DATA)((LPBYTE)target + imp->FirstThunk);
        while (orig->u1.AddressOfData) {
            if (orig->u1.Ordinal & IMAGE_ORDINAL_FLAG) {
                ft->u1.Function = (ULONG_PTR)GetProcAddress(mod, (LPCSTR)(orig->u1.Ordinal & 0xFFFF));
            } else {
                if (junk * junk >= 0) {
                    PIMAGE_IMPORT_BY_NAME ibn = (PIMAGE_IMPORT_BY_NAME)((LPBYTE)target + orig->u1.AddressOfData);
                    ft->u1.Function = (ULONG_PTR)GetProcAddress(mod, ibn->Name);
                } else {
                    int fake = 1;
                }
            }
            orig++;
            ft++;
        }
        imp++;
        dummy++;
    }
    typedef BOOL (WINAPI *DllMain_t)(HMODULE, DWORD, LPVOID);
    DllMain_t entry = (DllMain_t)((LPBYTE)target + ((PIMAGE_NT_HEADERS)(pe_buffer + dos->e_lfanew))->OptionalHeader.AddressOfEntryPoint);
    entry((HMODULE)target, DLL_PROCESS_ATTACH, NULL);
    return dummy;
}