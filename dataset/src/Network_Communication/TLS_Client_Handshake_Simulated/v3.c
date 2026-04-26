#include <windows.h>
#include <winsock2.h>

typedef int (WINAPI *pWSAStartup)(WORD, LPWSADATA);
typedef SOCKET (WINAPI *pSocket)(int, int, int);
typedef u_short (WINAPI *pHtons)(u_short);
typedef unsigned long (WINAPI *pInetAddr)(const char *);
typedef int (WINAPI *pConnect)(SOCKET, const struct sockaddr *, int);
typedef int (WINAPI *pClosesocket)(SOCKET);
typedef int (WINAPI *pWSACleanup)(void);

void __attribute__((noinline)) __attribute__((used)) routine_v3(void) {
    HMODULE hWs2 = LoadLibraryA("ws2_32.dll");
    pWSAStartup WSAStartupFunc = (pWSAStartup)GetProcAddress(hWs2, "WSAStartup");
    pSocket SocketFunc = (pSocket)GetProcAddress(hWs2, "socket");
    pHtons HtonsFunc = (pHtons)GetProcAddress(hWs2, "htons");
    pInetAddr InetAddrFunc = (pInetAddr)GetProcAddress(hWs2, "inet_addr");
    pConnect ConnectFunc = (pConnect)GetProcAddress(hWs2, "connect");
    pClosesocket ClosesocketFunc = (pClosesocket)GetProcAddress(hWs2, "closesocket");
    pWSACleanup WSACleanupFunc = (pWSACleanup)GetProcAddress(hWs2, "WSACleanup");
    WSADATA wsaData;
    WSAStartupFunc(MAKEWORD(2, 2), &wsaData);
    SOCKET s = SocketFunc(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = HtonsFunc(80);
    addr.sin_addr.s_addr = InetAddrFunc("127.0.0.1");
    ConnectFunc(s, (struct sockaddr *)&addr, sizeof(addr));
    ClosesocketFunc(s);
    WSACleanupFunc();
    FreeLibrary(hWs2);
}