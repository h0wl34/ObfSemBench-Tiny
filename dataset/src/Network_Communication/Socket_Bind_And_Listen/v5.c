#include <winsock2.h>

int __attribute__((noinline)) __attribute__((used)) routine_e_v5(int port){
    int state = 1;
    SOCKET s = -1;
    WSADATA w;
    struct sockaddr_in a;
    while (state != 0) {
        switch (state) {
            case 1: state = (WSAStartup(0x0202, &w) == 0) ? 2 : 0; break;
            case 2: s = socket(2, 1, 6); state = (s != -1) ? 3 : 0; break;
            case 3: 
                a.sin_family = 2; a.sin_port = htons(port); a.sin_addr.s_addr = 0;
                state = (bind(s, (struct sockaddr*)&a, 16) == 0) ? 4 : 5; break;
            case 4: listen(s, 5); state = 6; break;
            case 5: closesocket(s); s = -1; state = 0; break;
            case 6: state = 0; break;
        }
    }
    return (int)s;
}