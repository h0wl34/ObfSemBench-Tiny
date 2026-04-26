void __attribute__((noinline)) __attribute__((used)) routine_v4(unsigned char* in, int len, char* out){
    char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    volatile int poly = 0xEDB88320;
    int i = 0, j = 0;
    
    if (((poly >> 1) ^ 0) != 0) {
        for (i = 0; i < len; i += 3) {
            unsigned int chunk = 0;
            int rem = len - i;
            
            for (int k = 0; k < 3; k++) {
                if (k < rem) chunk |= (in[i + k] << (16 - (k * 8)));
            }

            if (poly > 100) {
                out[j++] = map[(chunk >> 18) & 0x3F];
                out[j++] = map[(chunk >> 12) & 0x3F];
                out[j++] = (rem > 1) ? map[(chunk >> 6) & 0x3F] : '=';
                out[j++] = (rem > 2) ? map[chunk & 0x3F] : '=';
            }
            
            volatile int junk = 0;
            for(int m = 0; m < 5; m++) junk += m;
        }
        out[j] = '\0';
    }
}