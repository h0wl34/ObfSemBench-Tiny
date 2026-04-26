unsigned int __attribute__((noinline)) __attribute__((used)) routine_v5(unsigned char* data, int len){
    unsigned int crc = 0xFFFFFFFF;
    int i = 0;
    int j = 0;
    int state = 10;

    while (state != 100) {
        switch (state) {
            case 10:
                i = 0;
                state = 20;
                break;
            case 20:
                if (i < len) state = 30;
                else state = 60;
                break;
            case 30:
                crc ^= data[i];
                j = 0;
                state = 40;
                break;
            case 40:
                if (j < 8) state = 50;
                else {
                    i++;
                    state = 20;
                }
                break;
            case 50:
                if (crc & 1) crc = (crc >> 1) ^ 0xEDB88320;
                else crc >>= 1;
                j++;
                state = 40;
                break;
            case 60:
                crc = ~crc;
                state = 100;
                break;
        }
    }
    return crc;
}