#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int check = 0;
    volatile int x = 10;
    if ((x * x) >= 100) {
        SID_IDENTIFIER_AUTHORITY auth = SECURITY_NT_AUTHORITY;
        PSID p;
        if (AllocateAndInitializeSid(&auth, 2, 32, 544, 0, 0, 0, 0, 0, 0, &p)) {
            BOOL b;
            if (CheckTokenMembership(NULL, p, &b)) check = b ? 1 : 0;
            FreeSid(p);
        }
    }
    return check;
}