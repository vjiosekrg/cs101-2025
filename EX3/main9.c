#include <stdio.h>
#include <stdlib.h>
int main() {
    int x = -9;
    int y = 9;
    int z = 1;
    int sgn = x / abs(x);
    printf("%d", x * 100 + sgn * y * 10 + sgn * z);
}