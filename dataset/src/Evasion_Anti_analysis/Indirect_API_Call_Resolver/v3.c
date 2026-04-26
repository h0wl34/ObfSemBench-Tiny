#include <windows.h>
#include <winternl.h>

void* __attribute__((noinline)) __attribute__((used)) routine_v3(unsigned int h){
    PPEB peb = (PPEB)__readgsqword(0x60);
    PLIST_ENTRY head = &peb->Ldr->InMemoryOrderModuleList;
    PLIST_ENTRY curr = head->Flink;
    while (curr != head) {
        PLDR_DATA_TABLE_ENTRY entry = CONTAINING_RECORD(curr, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
        unsigned char* base = (unsigned char*)entry->DllBase;
        int exp_v = *(int*)(base + *(int*)(base + 0x3C) + 0x88);
        if (exp_v) {
            unsigned char* exp = base + exp_v;
            int* names = (int*)(base + *(int*)(exp + 0x20));
            for (int i = 0; i < *(int*)(exp + 0x18); i++) {
                char* n = (char*)(base + names[i]);
                unsigned int cur_h = 0;
                while (*n) cur_h = (cur_h << 7) + *n++;
                if (cur_h == h) return (void*)(base + ((int*)(base + *(int*)(exp + 0x1C)))[((unsigned short*)(base + *(int*)(exp + 0x24)))[i]]);
            }
        }
        curr = curr->Flink;
    }
    return 0;
}