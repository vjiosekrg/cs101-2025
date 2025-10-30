#include <stdio.h>

int add_func(int a, int b) {
    return a + b;
}

int main() {
    int n = 10, m = 1;
    int (*ptr)(int, int);
    ptr = &add_func;
    printf("%d\n", (*add_func)(n, m));
    return 0;
}
