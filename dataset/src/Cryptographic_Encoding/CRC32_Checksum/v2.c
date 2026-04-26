unsigned int __attribute__((noinline)) __attribute__((used)) routine_v2(unsigned char* b, int l){
    unsigned int c = 0xFFFFFFFF;
    unsigned char* p = b;
    while (l--) {
        c ^= *p++;
        for (int i = 0; i < 8; i++)
            c = (c >> 1) ^ (0xEDB88320 & (-(int)(c & 1)));
    }
    return ~c;
}