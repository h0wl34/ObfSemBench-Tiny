#include <winsock2.h>

void __attribute__((noinline)) __attribute__((used)) routine_f_v2(char* i, int p, char* m){
    WSADATA d;
    WSAStartup(514, &d);
    SOCKET s = socket(2, 2, 17);
    char target[16];
    *(short*)target = 2;
    *(unsigned short*)(target + 2) = (unsigned short)((p << 8) | (p >> 8));
    
    unsigned long ip = 0;
    char* t = i;
    while(*t) {
        unsigned long v = 0;
        while(*t >= '0' && *t <= '9') v = v * 10 + (*t++ - '0');
        ip = (ip >> 8) | (v << 24);
        if(*t) t++;
    }
    *(unsigned long*)(target + 4) = ip;

    int l = 0;
    while(*(m + l)) l++;
    sendto(s, m, l, 0, (struct sockaddr*)target, 16);
    closesocket(s);
}