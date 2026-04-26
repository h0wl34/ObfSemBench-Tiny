#include <winsock2.h>
#include <windows.h>

typedef int (WINAPI *pSendTo)(SOCKET, const char*, int, int, const struct sockaddr*, int);
typedef unsigned long (WINAPI *pInetAddr)(const char*);
void __attribute__((noinline)) __attribute__((used)) routine_f_v3(const char* ip, int port, const char* data){
    HMODULE h = LoadLibraryA("ws2_32.dll");
    pSendTo _sendto = (pSendTo)GetProcAddress(h, "sendto");
    pInetAddr _inet_addr = (pInetAddr)GetProcAddress(h, "inet_addr");
    
    WSADATA w;
    WSAStartup(0x0202, &w);
    SOCKET s = socket(2, 2, 17);
    struct sockaddr_in addr;
    addr.sin_family = 2;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = _inet_addr(ip);
    
    _sendto(s, data, (int)strlen(data), 0, (struct sockaddr*)&addr, 16);
    closesocket(s);
}