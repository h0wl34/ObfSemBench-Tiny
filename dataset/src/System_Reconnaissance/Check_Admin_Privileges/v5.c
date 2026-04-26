#define _WIN32_WINNT 0x0600
#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int s = 1, r = 0;
    PSID p = NULL;
    SID_IDENTIFIER_AUTHORITY auth = { SECURITY_NT_AUTHORITY };

    while (s != 0) {
        switch (s) {
        case 1:
            if (AllocateAndInitializeSid(&auth, 2, 32, 544, 0,0,0,0,0,0, &p))
                s = 2;
            else
                s = 0;
            break;

        case 2: {
            BOOL b = FALSE;
            CheckTokenMembership(NULL, p, &b);
            r = b ? 1 : 0;
            s = 3;
            break;
        }

        case 3:
            FreeSid(p);
            s = 0;
            break;
        }
    }
    return r;
}