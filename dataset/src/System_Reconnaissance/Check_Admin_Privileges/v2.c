#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v2(){
    unsigned char s[64];
    SID_IDENTIFIER_AUTHORITY auth = {0,0,0,0,0,5};
    PSID p = (PSID)s;
    InitializeSid(p, &auth, 2);
    *(GetSidSubAuthority(p, 0)) = 32;
    *(GetSidSubAuthority(p, 1)) = 544;
    BOOL r = 0;
    CheckTokenMembership(0, p, &r);
    return (int)r;
}