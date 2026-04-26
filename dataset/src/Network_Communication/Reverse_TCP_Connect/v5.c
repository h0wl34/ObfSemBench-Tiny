#include <winsock2.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* ip, int port){
    int state = 5;
    WSADATA w;
    SOCKET s = INVALID_SOCKET;
    struct sockaddr_in a;

    while (state != 0) {
        switch (state) {
            case 5:
                state = (WSAStartup(0x0202, &w) == 0) ? 12 : 0;
                break;
            case 12:
                s = socket(2, 1, 6);
                state = (s != INVALID_SOCKET) ? 19 : 33;
                break;
            case 19:
                a.sin_family = 2;
                a.sin_addr.s_addr = inet_addr(ip);
                a.sin_port = htons((u_short)port);
                state = 24;
                break;
            case 24:
                if (connect(s, (struct sockaddr*)&a, sizeof(a)) != -1) state = 28;
                else state = 28;
                break;
            case 28:
                if (s != INVALID_SOCKET) closesocket(s);
                state = 33;
                break;
            case 33:
                WSACleanup();
                state = 0;
                break;
            default:
                state = 0;
                break;
        }
    }
}