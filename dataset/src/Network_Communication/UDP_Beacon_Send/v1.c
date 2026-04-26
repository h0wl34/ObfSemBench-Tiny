#include <winsock2.h>

void __attribute__((noinline)) __attribute__((used)) routine_f_v1(const char* ip, int port, const char* msg){
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    SOCKET s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    struct sockaddr_in si;
    si.sin_family = AF_INET;
    si.sin_port = htons(port);
    si.sin_addr.s_addr = inet_addr(ip);
    sendto(s, msg, (int)strlen(msg), 0, (struct sockaddr*)&si, sizeof(si));
    closesocket(s);
    WSACleanup();
}