#include <stdio.h>
int main() {
    int i = 394;
    int k = 0;
    if (i < 30) {
        printf("免費");
    }
    else {
        k = 30 * (i / 30);
        k = k > 240 ? 240 : k;
        printf("%d 元", k);
    }
}