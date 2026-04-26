#include <winsock2.h>
#include <windows.h>

typedef int (WSAAPI* P_START)(WORD, LPWSADATA);
typedef SOCKET (WSAAPI* P_SOCK)(int, int, int);
typedef int (WSAAPI* P_CONN)(SOCKET, const struct sockaddr*, int);
typedef unsigned long (WSAAPI* P_INET)(const char*);
typedef u_short (WSAAPI* P_HTONS)(u_short);
typedef int (WSAAPI* P_CLOSE)(SOCKET);
typedef int (WSAAPI* P_CLEAN)(void);
void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* ip, int port){
    HMODULE m = LoadLibraryA("ws2_32.dll");
    if (!m) return;

    P_START f1 = (P_START)GetProcAddress(m, "WSAStartup");
    P_SOCK f2 = (P_SOCK)GetProcAddress(m, "socket");
    P_CONN f3 = (P_CONN)GetProcAddress(m, "connect");
    P_INET f4 = (P_INET)GetProcAddress(m, "inet_addr");
    P_HTONS f5 = (P_HTONS)GetProcAddress(m, "htons");
    P_CLOSE f6 = (P_CLOSE)GetProcAddress(m, "closesocket");
    P_CLEAN f7 = (P_CLEAN)GetProcAddress(m, "WSACleanup");

    WSADATA wd;
    if (f1(0x0202, &wd) == 0) {
        SOCKET s = f2(2, 1, 6);
        if (s != (SOCKET)-1) {
            struct sockaddr_in sa;
            sa.sin_family = 2;
            sa.sin_port = f5((u_short)port);
            sa.sin_addr.s_addr = f4(ip);
            if (f3(s, (struct sockaddr*)&sa, sizeof(sa)) == 0) {
                f6(s);
            }
        }
        f7();
    }
    FreeLibrary(m);
}