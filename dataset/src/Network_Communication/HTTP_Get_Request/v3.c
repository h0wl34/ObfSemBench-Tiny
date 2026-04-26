#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

typedef int (WSAAPI* PFN_WSASTARTUP)(WORD, LPWSADATA);
typedef int (WSAAPI* PFN_GETADDRINFO)(PCSTR, PCSTR, const ADDRINFOA*, ADDRINFOA**);
typedef SOCKET (WSAAPI* PFN_SOCKET)(int, int, int);
typedef int (WSAAPI* PFN_CONNECT)(SOCKET, const struct sockaddr*, int);
typedef int (WSAAPI* PFN_SEND)(SOCKET, const char*, int, int);
typedef int (WSAAPI* PFN_RECV)(SOCKET, char*, int, int);
typedef int (WSAAPI* PFN_CLOSESOCKET)(SOCKET);
typedef int (WSAAPI* PFN_WSACLEANUP)(void);
typedef void (WSAAPI* PFN_FREEADDRINFO)(PADDRINFOA);
void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* host, const char* path){
    HMODULE hWs2 = LoadLibraryA("ws2_32.dll");
    if (!hWs2) return;

    PFN_WSASTARTUP pWSAStartup = (PFN_WSASTARTUP)GetProcAddress(hWs2, "WSAStartup");
    PFN_GETADDRINFO pGetAddrInfo = (PFN_GETADDRINFO)GetProcAddress(hWs2, "getaddrinfo");
    PFN_SOCKET pSocket = (PFN_SOCKET)GetProcAddress(hWs2, "socket");
    PFN_CONNECT pConnect = (PFN_CONNECT)GetProcAddress(hWs2, "connect");
    PFN_SEND pSend = (PFN_SEND)GetProcAddress(hWs2, "send");
    PFN_RECV pRecv = (PFN_RECV)GetProcAddress(hWs2, "recv");
    PFN_CLOSESOCKET pClosesocket = (PFN_CLOSESOCKET)GetProcAddress(hWs2, "closesocket");
    PFN_WSACLEANUP pWSACleanup = (PFN_WSACLEANUP)GetProcAddress(hWs2, "WSACleanup");
    PFN_FREEADDRINFO pFreeAddrInfo = (PFN_FREEADDRINFO)GetProcAddress(hWs2, "freeaddrinfo");

    WSADATA wsaData;
    if (pWSAStartup(0x0202, &wsaData) != 0) return;

    struct addrinfo hints, *res = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (pGetAddrInfo(host, "80", &hints, &res) == 0) {
        SOCKET s = pSocket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (s != INVALID_SOCKET) {
            if (pConnect(s, res->ai_addr, (int)res->ai_addrlen) != SOCKET_ERROR) {
                char req[512];
                wsprintfA(req, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
                pSend(s, req, (int)strlen(req), 0);
                char buf[1024];
                while (pRecv(s, buf, 1024, 0) > 0);
            }
            pClosesocket(s);
        }
        pFreeAddrInfo(res);
    }
    pWSACleanup();
    FreeLibrary(hWs2);
}