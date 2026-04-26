#include <winsock2.h>

int __attribute__((noinline)) __attribute__((used)) routine_e_v4(int port){
    int x = 500;
    int y = 1000;
    WSADATA w;
    if (WSAStartup(0x0202, &w) == 0) {
        SOCKET s = socket(2, 1, 6);
        if (x * 2 <= y) {
            struct sockaddr_in a;
            a.sin_family = 2;
            a.sin_port = htons(port);
            a.sin_addr.s_addr = 0;
            if (bind(s, (struct sockaddr*)&a, sizeof(a)) != -1) {
                while(x > 1000) { x--; }
                listen(s, 128);
                return (int)s;
            }
        }
    }
    return -1;
}