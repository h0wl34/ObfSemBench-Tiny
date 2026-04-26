#include <string.h>
#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) apply_replace_v3(char *orig, char *rep, char *with){
    char *ins;
    char *tmp;
    int len_rep;
    int len_with;
    int len_front;
    int count;
    ins = strstr(orig, rep);
    if (!ins) return;
    len_rep = strlen(rep);
    len_with = strlen(with);
    len_front = ins - orig;
    memmove(ins + len_with, ins + len_rep, strlen(ins + len_rep) + 1);
    memcpy(ins, with, len_with);
    apply_replace_v3(ins + len_with, rep, with);
}