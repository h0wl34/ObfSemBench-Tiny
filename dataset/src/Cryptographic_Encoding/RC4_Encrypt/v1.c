void __attribute__((noinline)) __attribute__((used)) routine_v1(unsigned char* data, int data_len, unsigned char* key, int key_len){
    unsigned char S[256];
    int i, j = 0, t;

    for (i = 0; i < 256; i++)
        S[i] = i;

    for (i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key_len]) % 256;
        unsigned char tmp = S[i];
        S[i] = S[j];
        S[j] = tmp;
    }

    i = 0;
    j = 0;
    for (int k = 0; k < data_len; k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        unsigned char tmp = S[i];
        S[i] = S[j];
        S[j] = tmp;
        t = (S[i] + S[j]) % 256;
        data[k] ^= S[t];
    }
}