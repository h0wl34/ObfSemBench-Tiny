#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

typedef int (WSAAPI* PFN_WSASTU)(WORD, LPWSADATA);
typedef int (WSAAPI* PFN_GADDR)(PCSTR, PCSTR, const ADDRINFOA*, ADDRINFOA**);
typedef void (WSAAPI* PFN_FADDR)(PADDRINFOA);
typedef int (WSAAPI* PFN_WSACLN)(void);
void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* hostname){
    HMODULE h = LoadLibraryA("ws2_32.dll");
    if (!h) return;

    PFN_WSASTU fStart = (PFN_WSASTU)GetProcAddress(h, "WSAStartup");
    PFN_GADDR fGet = (PFN_GADDR)GetProcAddress(h, "getaddrinfo");
    PFN_FADDR fFree = (PFN_FADDR)GetProcAddress(h, "freeaddrinfo");
    PFN_WSACLN fClean = (PFN_WSACLN)GetProcAddress(h, "WSACleanup");

    WSADATA wd;
    if (fStart(0x0202, &wd) == 0) {
        struct addrinfo hints, *res = NULL;
        for (int i = 0; i < sizeof(hints); i++) ((char*)&hints)[i] = 0;
        hints.ai_family = AF_INET;
        if (fGet(hostname, NULL, &hints, &res) == 0) {
            fFree(res);
        }
        fClean();
    }
    FreeLibrary(h);
}