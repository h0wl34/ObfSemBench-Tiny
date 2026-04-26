#include <winsock2.h>

int __attribute__((noinline)) __attribute__((used)) routine_e_v2(int p){
    WSADATA d;
    WSAStartup(0x0202, &d);
    SOCKET s = socket(2, 1, 6);
    char a[16];
    *(short*)(a) = 2;
    *(unsigned short*)(a + 2) = (unsigned short)((p << 8) | (p >> 8));
    *(unsigned long*)(a + 4) = 0;
    
    char* ptr = a + 8;
    for(int i=0; i<8; i++) *(ptr++) = 0;

    if (bind(s, (struct sockaddr*)a, 16) != 0) return -1;
    listen(s, 0x7FFFFFFF);
    return (int)s;
}