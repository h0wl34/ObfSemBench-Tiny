void __attribute__((noinline)) __attribute__((used)) routine_v5(unsigned char* data, int len, unsigned char* key, int klen){
    unsigned char s[256];
    int i = 0, j = 0, k = 0;
    int state = 0;

    while (state != 6) {
        switch (state) {
            case 0:
                for (int m = 0; m < 256; m++) s[m] = m;
                i = 0; j = 0;
                state = 1;
                break;
            case 1:
                if (i < 256) {
                    j = (j + s[i] + key[i % klen]) % 256;
                    unsigned char t = s[i];
                    s[i] = s[j];
                    s[j] = t;
                    i++;
                } else {
                    i = 0; j = 0; k = 0;
                    state = 2;
                }
                break;
            case 2:
                if (k < len) state = 3;
                else state = 6;
                break;
            case 3:
                i = (i + 1) % 256;
                j = (j + s[i]) % 256;
                state = 4;
                break;
            case 4:
                {
                    unsigned char t = s[i];
                    s[i] = s[j];
                    s[j] = t;
                }
                state = 5;
                break;
            case 5:
                data[k] ^= s[(s[i] + s[j]) % 256];
                k++;
                state = 2;
                break;
        }
    }
}