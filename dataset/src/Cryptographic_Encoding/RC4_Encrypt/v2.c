void __attribute__((noinline)) __attribute__((used)) routine_v2(unsigned char* d, int dl, unsigned char* k, int kl){
    unsigned char s[256];
    unsigned char *ps = s;
    int i = 0, j = 0;

    do {
        *(ps + i) = (unsigned char)i;
    } while (++i < 256);

    for (i = 0, j = 0; i < 256; i++) {
        j = (j + *(ps + i) + *(k + (i % kl))) & 0xFF;
        unsigned char t = *(ps + i);
        *(ps + i) = *(ps + j);
        *(ps + j) = t;
    }

    i = 0; j = 0;
    unsigned char* p = d;
    while (dl--) {
        i = (i + 1) & 0xFF;
        j = (j + *(ps + i)) & 0xFF;
        unsigned char t = *(ps + i);
        *(ps + i) = *(ps + j);
        *(ps + j) = t;
        *p++ ^= *(ps + ((*(ps + i) + *(ps + j)) & 0xFF));
    }
}