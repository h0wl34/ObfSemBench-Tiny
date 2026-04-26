#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* host, const char* path){
    int state = 0;
    WSADATA wsa;
    SOCKET s = INVALID_SOCKET;
    struct addrinfo* res = NULL;
    struct addrinfo hints;
    char req[512];
    char buf[1024];

    while (state != -1) {
        switch (state) {
            case 0:
                if (WSAStartup(0x0202, &wsa) == 0) state = 1;
                else state = -1;
                break;
            case 1:
                memset(&hints, 0, sizeof(hints));
                hints.ai_family = AF_INET;
                hints.ai_socktype = SOCK_STREAM;
                if (getaddrinfo(host, "80", &hints, &res) == 0) state = 2;
                else state = 6;
                break;
            case 2:
                s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
                if (s != INVALID_SOCKET) state = 3;
                else state = 5;
                break;
            case 3:
                if (connect(s, res->ai_addr, (int)res->ai_addrlen) != SOCKET_ERROR) state = 4;
                else state = 5;
                break;
            case 4:
                wsprintfA(req, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
                send(s, req, (int)strlen(req), 0);
                while (recv(s, buf, 1024, 0) > 0);
                state = 5;
                break;
            case 5:
                if (s != INVALID_SOCKET) closesocket(s);
                state = 6;
                break;
            case 6:
                if (res) freeaddrinfo(res);
                WSACleanup();
                state = -1;
                break;
        }
    }
}