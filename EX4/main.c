#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {0,1,2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    FILE *fp = fopen("./a.bin", "wb");
    if (fp == NULL) {
        perror("open file");
        exit(1);
    }
    fwrite(a, sizeof a[0], 3, fp);
    fwrite(b, sizeof b[0], 4, fp);
    fwrite(c, sizeof c[0], 3, fp);
    fclose(fp);

    int ra[3] = {0};
    char rb[4] = {0};
    float rc[3] = {0};

    FILE *fp2 = fopen("./a.bin", "rb");
    if (fp2 == NULL) {
        perror("open file");
        exit(1);
    }
    fread(ra, sizeof ra[0], 3, fp2);
    fread(rb, sizeof rb[0], 4, fp2);
    fread(rc, sizeof rc[0], 3, fp2);

    printf("%d %d %d\n", ra[0], ra[1], ra[2]);
    printf("%c %c %c\n", rb[0], rb[1], rb[2]);
    printf("%f %f %f\n", rc[0], rc[1], rc[2]);
}