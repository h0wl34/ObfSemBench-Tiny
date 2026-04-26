void __attribute__((noinline)) __attribute__((used)) routine_v5(unsigned char* data, int len, unsigned char* key, int klen){
    int state = 100;
    int idx = 0;
    while (state != 500) {
        switch (state) {
            case 100:
                idx = 0;
                state = 200;
                break;
            case 200:
                if (idx < len) {
                    state = 300;
                } else {
                    state = 500;
                }
                break;
            case 300:
                data[idx] = data[idx] ^ key[idx % klen];
                state = 400;
                break;
            case 400:
                idx++;
                state = 200;
                break;
            default:
                state = 500;
                break;
        }
    }
}