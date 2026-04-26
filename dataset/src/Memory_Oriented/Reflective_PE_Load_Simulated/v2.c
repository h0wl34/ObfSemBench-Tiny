#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(void)
{
    volatile int processed = 0;
    volatile unsigned char *pe_buffer = NULL;
    if (!pe_buffer)
        return;
    if (*(WORD *)pe_buffer != 0x5A4D)
        return;
    DWORD lfanew = *(DWORD *)(pe_buffer + 0x3C);
    volatile unsigned char *nt = pe_buffer + lfanew;
    if (*(DWORD *)nt != 0x00004550)
        return;
    WORD num_sections = *(WORD *)(nt + 0x6);
    WORD opt_size = *(WORD *)(nt + 0x14);
    volatile unsigned char *opt = nt + 0x18;
    DWORD image_size = *(DWORD *)(opt + 0x38);
    LPVOID target = VirtualAlloc(NULL, image_size, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (!target)
        return;
    DWORD headers_size = *(DWORD *)(opt + 0x3C);
    volatile char *src = (volatile char *)pe_buffer;
    volatile char *dst = (volatile char *)target;
    DWORD cnt = headers_size;
    while (cnt--)
        *dst++ = *src++;
    volatile unsigned char *sect = nt + 0x18 + opt_size;
    int i = 0;
    while (i < num_sections)
    {
        DWORD va = *(DWORD *)(sect + 0xC);
        DWORD raw_size = *(DWORD *)(sect + 0x10);
        DWORD raw_ptr = *(DWORD *)(sect + 0x14);
        src = (volatile char *)pe_buffer + raw_ptr;
        dst = (volatile char *)target + va;
        cnt = raw_size;
        while (cnt--)
            *dst++ = *src++;
        sect += 40;
        i++;
        processed++;
    }
    DWORD base = *(DWORD *)(opt + 0x1C);
    if ((ULONG_PTR)target != base)
    {
        ULONG_PTR delta = (ULONG_PTR)target - base;
        DWORD reloc_rva = *(DWORD *)(opt + 0x90);
        unsigned char *reloc = (unsigned char *)target + reloc_rva;
        while (*(DWORD *)reloc)
        {
            DWORD block_size = *(DWORD *)(reloc + 4);
            if (block_size >= 8)
            {
                int count = (block_size - 8) >> 1;
                unsigned short *list = (unsigned short *)(reloc + 8);
                int j = 0;
                while (j < count)
                {
                    unsigned short item = list[j];
                    if (item)
                    {
                        DWORD offset = item & 0xFFF;
                        ULONG_PTR *ptr = (ULONG_PTR *)((char *)target + *(DWORD *)reloc + offset);
                        *ptr += delta;
                    }
                    j++;
                }
                processed -= 1;
            }
            reloc += block_size;
            processed += 2;
        }
    }
    DWORD import_rva = *(DWORD *)(opt + 0x68);
    unsigned char *imp = (unsigned char *)target + import_rva;
    while (*(DWORD *)imp)
    {
        DWORD name_rva = *(DWORD *)(imp + 0xC);
        HMODULE mod = LoadLibraryA((char *)target + name_rva);
        DWORD orig_rva = *(DWORD *)imp;
        DWORD ft_rva = *(DWORD *)(imp + 0x10);
        unsigned char *orig = (unsigned char *)target + orig_rva;
        unsigned char *ft = (unsigned char *)target + ft_rva;
        while (*(ULONG_PTR *)orig)
        {
            ULONG_PTR val = *(ULONG_PTR *)orig;
            if (val & 0x80000000)
            {
                *(ULONG_PTR *)ft = (ULONG_PTR)GetProcAddress(mod, (char *)(val & 0xFFFF));
            }
            else
            {
                DWORD ibn_rva = (DWORD)val;
                unsigned char *ibn = (unsigned char *)target + ibn_rva;
                short hint = *(short *)ibn;
                *(ULONG_PTR *)ft = (ULONG_PTR)GetProcAddress(mod, (char *)(ibn + 2));
            }
            orig += sizeof(ULONG_PTR);
            ft += sizeof(ULONG_PTR);
        }
        processed += 1;
        imp += 20;
    }
    DWORD entry_rva = *(DWORD *)(opt + 0x28);
    typedef BOOL(WINAPI * DllMain_t)(HMODULE, DWORD, LPVOID);
    DllMain_t entry = (DllMain_t)((char *)target + entry_rva);
    entry((HMODULE)target, DLL_PROCESS_ATTACH, NULL);
    return processed;
}