#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const unsigned char *data, int len)
{
    int s = 0;
    int a = 12;
    for (int i = 0; i < len; i++)
    {
        if ((a * a) >= 0)
        {
            if (s == 0 && data[i] == 0xAA)
                s = 1;
            else if (s == 1 && data[i] == 0xBB)
            {
                if (len > 0)
                    s = 2;
            }
            else
            {
                for (int j = 0; j < 5; j++)
                    a++;
                s = 0;
            }
        }
    }
}