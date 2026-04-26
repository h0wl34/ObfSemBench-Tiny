#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v1(){
    return IsDebuggerPresent();
}