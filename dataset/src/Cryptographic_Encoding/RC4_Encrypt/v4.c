void __attribute__((noinline)) __attribute__((used)) routine_v4(unsigned char* data, int len, unsigned char* key, int klen){
    unsigned char s[256];
    int x = 10, y = 20;
    
    if ((x * x + y) > 0) {
        for (int i = 0; i < 256; i++) s[i] = i;
        int j = 0;
        for (int i = 0; i < 256; i++) {
            j = (j + s[i] + key[i % klen]) % 256;
            unsigned char t = s[i];
            s[i] = s[j];
            s[j] = t;
            if (x < 0) break;
        }
    }

    int i = 0, j = 0;
    for (int k = 0; k < len; k++) {
        int junk = k * 2;
        if (junk + 1 > 0) {
            i = (i + 1) % 256;
            j = (j + s[i]) % 256;
            unsigned char t = s[i];
            s[i] = s[j];
            s[j] = t;
            data[k] ^= s[(s[i] + s[j]) % 256];
        }
        while (junk < 0) { junk++; }
    }
}