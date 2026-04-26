#include <stdio.h>
#include <string.h>

void __attribute__((noinline)) __attribute__((used)) parse_cfg_a(const char *buf, const char *key, char *out){
    const char *line = buf;
    while (line) {
        const char *next = strchr(line, '\n');
        if (strncmp(line, key, strlen(key)) == 0) {
            const char *delim = strchr(line, '=');
            if (delim && (next == NULL || delim < next)) {
                size_t len = next ? (size_t)(next - (delim + 1)) : strlen(delim + 1);
                strncpy(out, delim + 1, len);
                out[len] = '\0';
                return;
            }
        }
        line = next ? next + 1 : NULL;
    }
}