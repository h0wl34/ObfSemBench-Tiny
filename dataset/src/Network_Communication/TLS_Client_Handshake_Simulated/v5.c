#include <winsock2.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(void) {
    WSADATA wsaData;
    SOCKET s = INVALID_SOCKET;
    struct sockaddr_in addr = {0};
    int state = 0;
    while (1) {
        switch (state) {
            case 0:
                WSAStartup(MAKEWORD(2, 2), &wsaData);
                state = 1;
                break;
            case 1:
                s = socket(AF_INET, SOCK_STREAM, 0);
                state = 2;
                break;
            case 2:
                addr.sin_family = AF_INET;
                addr.sin_port = htons(80);
                addr.sin_addr.s_addr = inet_addr("127.0.0.1");
                state = 3;
                break;
            case 3:
                connect(s, (struct sockaddr *)&addr, sizeof(addr));
                state = 4;
                break;
            case 4:
                closesocket(s);
                state = 5;
                break;
            case 5:
                WSACleanup();
                return;
        }
    }
}