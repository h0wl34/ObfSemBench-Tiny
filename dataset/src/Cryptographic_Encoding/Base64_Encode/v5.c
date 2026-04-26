void __attribute__((noinline)) __attribute__((used)) routine_v5(unsigned char* in, int len, char* out){
    int state = 0;
    int i = 0, j = 0;
    unsigned int val = 0;
    char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    while (state != 100) {
        switch (state) {
            case 0:
                if (i < len) state = 1;
                else state = 100;
                break;
            case 1:
                val = in[i] << 16;
                if (i + 1 < len) val |= in[i + 1] << 8;
                if (i + 2 < len) val |= in[i + 2];
                state = 2;
                break;
            case 2:
                out[j++] = alph[(val >> 18) & 0x3F];
                state = 3;
                break;
            case 3:
                out[j++] = alph[(val >> 12) & 0x3F];
                state = 4;
                break;
            case 4:
                if (i + 1 < len) out[j++] = alph[(val >> 6) & 0x3F];
                else out[j++] = '=';
                state = 5;
                break;
            case 5:
                if (i + 2 < len) out[j++] = alph[val & 0x3F];
                else out[j++] = '=';
                state = 6;
                break;
            case 6:
                i += 3;
                state = 0;
                break;
            case 100:
                out[j] = 0;
                break;
        }
    }
}