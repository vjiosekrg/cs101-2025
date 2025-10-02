#include <stdio.h>

int main() {
    for (int i=1;i<7;i++) {
        for (int j=0;j<7-i-1;j++) {
            printf(" ");
        }
        for (int k=i;k>0;k--) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}