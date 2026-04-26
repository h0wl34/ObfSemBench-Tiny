void __attribute__((noinline)) __attribute__((used)) routine_v1(unsigned char* data, int data_len, unsigned char* key, int key_len){
    for (int i = 0; i < data_len; i++) {
        data[i] = data[i] ^ key[i % key_len];
    }
}