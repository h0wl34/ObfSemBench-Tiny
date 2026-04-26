void __attribute__((noinline)) __attribute__((used)) routine_v2(unsigned char* s, int l, char* d){
    char* t = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    while (l > 0) {
        *d++ = *(t + ((*s >> 2) & 0x3F));
        if (l > 2) {
            *d++ = *(t + (((*s & 0x03) << 4) | (*(s + 1) >> 4)));
            *d++ = *(t + (((*(s + 1) & 0x0F) << 2) | (*(s + 2) >> 6)));
            *d++ = *(t + (*(s + 2) & 0x3F));
        } else if (l == 2) {
            *d++ = *(t + (((*s & 0x03) << 4) | (*(s + 1) >> 4)));
            *d++ = *(t + ((*(s + 1) & 0x0F) << 2));
            *d++ = '=';
        } else if (l == 1) {
            *d++ = *(t + ((*s & 0x03) << 4));
            *d++ = '=';
            *d++ = '=';
        }
        l -= 3;
        s += 3;
    }
    *d = 0;
}