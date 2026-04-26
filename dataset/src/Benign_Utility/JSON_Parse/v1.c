#include <string.h>
#include <stdlib.h>

char *extract_json_v1(const char *json, const char *key) {
    char search[128];
    sprintf(search, "\"%s\"", key);
    char *pos = strstr(json, search);
    if (!pos) return NULL;
    pos = strchr(pos + strlen(search), ':');
    if (!pos) return NULL;
    pos = strchr(pos, '\"');
    if (!pos) return NULL;
    char *start = pos + 1;
    char *end = strchr(start, '\"');
    if (!end) return NULL;
    size_t len = end - start;
    char *res = (char *)malloc(len + 1);
    strncpy(res, start, len);
    res[len] = '\0';
    return res;
}