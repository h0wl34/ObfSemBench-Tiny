#include <winsock2.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(void) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(s, (struct sockaddr *)&addr, sizeof(addr));
    closesocket(s);
    WSACleanup();
}