#include <stdio.h>
int main() {
    int i = 1900;
    scanf("%d", &i);
    int k = 0;
    i -= 1500;
    k += 70;
    if (i > 0) {
        k += 10 * (1 + i / 100 - (i % 100 == 0));
    }
    printf("%d 元", k);
}