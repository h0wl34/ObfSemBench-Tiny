void __attribute__((noinline)) __attribute__((used)) routine_v4(unsigned char* data, int len, unsigned char* key, int klen){
    volatile int a = 15;
    volatile int b = 30;
    
    if (((a * a) + (b * b)) >= 0) {
        for (int i = 0; i < len; i++) {
            int junk = 0;
            for (int j = 0; j < 3; j++) {
                junk += (i * j);
            }
            if (junk > 0x7FFFFFFF) {
                data[i] = 0xFF;
            }
            if (a + b > 10) {
                data[i] ^= key[i % klen];
            }
        }
    }
}