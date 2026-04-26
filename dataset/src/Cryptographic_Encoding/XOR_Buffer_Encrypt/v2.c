void __attribute__((noinline)) __attribute__((used)) routine_v2(unsigned char* buf, int sz, unsigned char* k, int ksz){
    unsigned char* p = buf;
    int i = 0;
    while (sz--) {
        *p++ ^= *(k + ((i << 4 >> 4) % ksz));
        i++;
    }
}