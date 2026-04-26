#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")
void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* hostname){
    WSADATA wsaData;
    struct addrinfo* result = NULL;
    struct addrinfo hints;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(hostname, NULL, &hints, &result) == 0) {
        freeaddrinfo(result);
    }

    WSACleanup();
}