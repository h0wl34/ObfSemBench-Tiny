unsigned int __attribute__((noinline)) __attribute__((used)) routine_v4(unsigned char* data, int len){
    volatile int x = 100;
    volatile int y = 200;
    unsigned int crc = 0xFFFFFFFF;

    if (((x * x) + y) > 0) {
        for (int i = 0; i < len; i++) {
            crc ^= data[i];
            for (int j = 0; j < 8; j++) {
                int predicate = (x + y) % 2;
                if (crc & 1) {
                    crc = (crc >> 1) ^ 0xEDB88320;
                } else {
                    crc >>= 1;
                }
                if (predicate > 2) x++; 
            }
            volatile int junk = 0;
            while(junk < 2) junk++;
        }
    }
    return ~crc;
}