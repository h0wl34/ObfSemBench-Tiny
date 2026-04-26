#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")
void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* host, const char* path){
    WSADATA wsaData;
    SOCKET sock = INVALID_SOCKET;
    struct addrinfo* result = NULL, hints;
    char request[512];
    char buffer[4096];
    int bytesReceived;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, "80", &hints, &result) != 0) {
        WSACleanup();
        return;
    }

    sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == INVALID_SOCKET) {
        freeaddrinfo(result);
        WSACleanup();
        return;
    }

    if (connect(sock, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR) {
        closesocket(sock);
        freeaddrinfo(result);
        WSACleanup();
        return;
    }

    wsprintfA(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    send(sock, request, (int)strlen(request), 0);

    do {
        bytesReceived = recv(sock, buffer, sizeof(buffer) - 1, 0);
    } while (bytesReceived > 0);

    closesocket(sock);
    freeaddrinfo(result);
    WSACleanup();
}