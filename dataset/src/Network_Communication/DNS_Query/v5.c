#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* hostname){
    int step = 100;
    WSADATA wsa;
    struct addrinfo* info = NULL;
    struct addrinfo hints;

    while (step != 0) {
        switch (step) {
            case 100:
                if (WSAStartup(0x0202, &wsa) == 0) step = 200;
                else step = 0;
                break;
            case 200:
                memset(&hints, 0, sizeof(hints));
                hints.ai_family = AF_UNSPEC;
                hints.ai_socktype = SOCK_STREAM;
                step = 300;
                break;
            case 300:
                if (getaddrinfo(hostname, NULL, &hints, &info) == 0) step = 400;
                else step = 500;
                break;
            case 400:
                if (info) freeaddrinfo(info);
                step = 500;
                break;
            case 500:
                WSACleanup();
                step = 0;
                break;
            default:
                step = 0;
                break;
        }
    }
}