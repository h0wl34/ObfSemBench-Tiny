#include <winsock2.h>
#include <windows.h>

typedef int (WINAPI *pWSAStartup)(WORD, LPWSADATA);
typedef SOCKET (WINAPI *pSocket)(int, int, int);
typedef int (WINAPI *pBind)(SOCKET, const struct sockaddr*, int);
typedef int (WINAPI *pListen)(SOCKET, int);
int __attribute__((noinline)) __attribute__((used)) routine_e_v3(int port){
    HMODULE h = LoadLibraryA("ws2_32.dll");
    pWSAStartup _WSAStartup = (pWSAStartup)GetProcAddress(h, "WSAStartup");
    pSocket _socket = (pSocket)GetProcAddress(h, "socket");
    pBind _bind = (pBind)GetProcAddress(h, "bind");
    pListen _listen = (pListen)GetProcAddress(h, "listen");

    WSADATA w;
    _WSAStartup(0x0202, &w);
    SOCKET s = _socket(2, 1, 6);
    
    struct sockaddr_in addr;
    addr.sin_family = 2;
    addr.sin_addr.s_addr = 0;
    addr.sin_port = ((port & 0xFF) << 8) | ((port & 0xFF00) >> 8);

    if (_bind(s, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
        _listen(s, 5);
    }
    return (int)s;
}