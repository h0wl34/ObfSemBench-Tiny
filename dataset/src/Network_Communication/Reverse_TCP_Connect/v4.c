#include <winsock2.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* ip, int port){
    int m = 100;
    int n = 200;
    for (int i = 0; i < 10; i++) { m += i; n -= i; }
    if (m + n < 0) return;

    WSADATA w;
    if (WSAStartup(0x0202, &w) != 0) return;

    if ((m * m) >= 0) {
        SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
        if (s != INVALID_SOCKET) {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons((u_short)port);
            addr.sin_addr.s_addr = inet_addr(ip);

            int junk = 7;
            while (junk > 10) { junk--; }

            if (connect(s, (struct sockaddr*)&addr, sizeof(addr)) != SOCKET_ERROR) {
                if (n != 0x999) closesocket(s);
            } else {
                closesocket(s);
            }
        }
    }
    WSACleanup();
}