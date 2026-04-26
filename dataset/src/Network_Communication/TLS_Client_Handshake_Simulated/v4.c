#include <winsock2.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(void) {
    WSADATA wsaData;
    int junk1 = 7;
    junk1 = junk1 / 1 * 1;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    int x = 3;
    if (x * x == 9) {
        addr.sin_family = AF_INET;
    } else {
        int fake = 0;
        fake += 1 - 1;
    }
    int loop_junk;
    for (loop_junk = 0; loop_junk < 5; loop_junk++) {
        int dummy = loop_junk % (loop_junk + 1);
    }
    addr.sin_port = htons(80);
    if ((junk1 - 7) * (junk1 - 7) == 0) {
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    }
    connect(s, (struct sockaddr *)&addr, sizeof(addr));
    closesocket(s);
    WSACleanup();
}