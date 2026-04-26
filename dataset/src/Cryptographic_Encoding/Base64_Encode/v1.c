void __attribute__((noinline)) __attribute__((used)) routine_v1(unsigned char* in, int in_len, char* out){
    char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int i, j;
    for (i = 0, j = 0; i < in_len; i += 3, j += 4) {
        int v = in[i] << 16;
        if (i + 1 < in_len) v |= in[i + 1] << 8;
        if (i + 2 < in_len) v |= in[i + 2];

        out[j] = table[(v >> 18) & 0x3F];
        out[j + 1] = table[(v >> 12) & 0x3F];
        if (i + 1 < in_len) out[j + 2] = table[(v >> 6) & 0x3F];
        else out[j + 2] = '=';
        if (i + 2 < in_len) out[j + 3] = table[v & 0x3F];
        else out[j + 3] = '=';
    }
    out[j] = '\0';
}