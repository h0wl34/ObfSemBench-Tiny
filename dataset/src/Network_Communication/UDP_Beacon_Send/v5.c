#include <winsock2.h>

void __attribute__((noinline)) __attribute__((used)) routine_f_v5(const char* i, int p, const char* m){
    int state = 10;
    SOCKET s;
    struct sockaddr_in addr;
    WSADATA w;
    while (state != 0) {
        switch (state) {
            case 10: WSAStartup(0x0202, &w); state = 20; break;
            case 20: s = socket(2, 2, 17); state = 30; break;
            case 30: 
                addr.sin_family = 2; addr.sin_port = htons(p); 
                addr.sin_addr.s_addr = inet_addr(i); state = 40; break;
            case 40: sendto(s, m, (int)strlen(m), 0, (struct sockaddr*)&addr, 16); state = 50; break;
            case 50: closesocket(s); WSACleanup(); state = 0; break;
        }
    }
}