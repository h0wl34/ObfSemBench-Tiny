#include <winsock2.h>

void __attribute__((noinline)) __attribute__((used)) routine_f_v4(const char* ip, int port, char* msg){
    int c = 0;
    for(int i=0; i<100; i++) c += i;
    if (c == 4950) {
        WSADATA w;
        WSAStartup(0x0202, &w);
        SOCKET s = socket(2, 2, 17);
        if (s != -1) {
            struct sockaddr_in a;
            a.sin_family = 2;
            a.sin_port = htons(port);
            a.sin_addr.s_addr = inet_addr(ip);
            int len = 0;
            while(msg[len]) len++;
            sendto(s, msg, len, 0, (struct sockaddr*)&a, 16);
            closesocket(s);
        }
    }
}