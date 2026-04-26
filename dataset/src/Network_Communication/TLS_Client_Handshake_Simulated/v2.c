#include <winsock2.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(void) {
    WSADATA wsaData;
    WSAStartup((unsigned short)((2 << 8) | 2), &wsaData);
    SOCKET s = socket(2, 1, 0);
    unsigned char addr[16] = {0};
    *(unsigned short *)addr = 2;
    unsigned short port = 80;
    *(unsigned short *)(addr + 2) = ((port & 0xFF) << 8) | ((port >> 8) & 0xFF);
    unsigned long ip = ((unsigned long)127 << 24) | ((unsigned long)0 << 16) | ((unsigned long)0 << 8) | 1;
    unsigned long net_ip = ((ip & 0xFF) << 24) | (((ip >> 8) & 0xFF) << 16) | (((ip >> 16) & 0xFF) << 8) | (ip >> 24);
    *(unsigned long *)(addr + 4) = net_ip;
    connect(s, (struct sockaddr *)addr, 16);
    closesocket(s);
    WSACleanup();
}