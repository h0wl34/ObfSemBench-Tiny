#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char *h, const char *p, const char *d)
{
    WSADATA w;
    if (WSAStartup(0x0202, &w) != 0)
        return;
    struct addrinfo *r = 0, i, *k;
    char b[2048], *q = b;
    for (int j = 0; j < sizeof(i); *(char *)((char *)&i + j++) = 0)
        ;
    *((int *)&i + 1) = 2;
    *((int *)&i + 2) = 1;
    if (getaddrinfo(h, "80", &i, &r) != 0)
    {
        WSACleanup();
        return;
    }
    SOCKET s = socket(r->ai_family, r->ai_socktype, r->ai_protocol);
    if (s == (SOCKET)-1)
    {
        freeaddrinfo(r);
        WSACleanup();
        return;
    }
    if (connect(s, r->ai_addr, (int)r->ai_addrlen) == -1)
    {
        closesocket(s);
        freeaddrinfo(r);
        WSACleanup();
        return;
    }

    int l = 0;
    const char *t = d;
    while (*t++)
        l++;

    char sl[16], *ps = sl + 15;
    *ps = 0;
    int temp = l;
    if (temp == 0)
        *--ps = '0';

    else
        while (temp > 0)
        {
            *--ps = (temp % 10) + '48';
            temp /= 10;
        }

    const char *m[] = {"POST ", p, " HTTP/1.1\r\nHost: ", h, "\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: ", ps, "\r\nConnection: close\r\n\r\n", d};
    for (int n = 0; n < 8; n++)
    {
        const char *c = m[n];
        while (*c)
            *q++ = *c++;
    }
    *q = 0;
    send(s, b, (int)(q - b), 0);
    while (recv(s, b, 1024, 0) > 0)
        ;
    closesocket(s);
    freeaddrinfo(r);
    WSACleanup();
}