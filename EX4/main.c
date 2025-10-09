#include <stdio.h>
#include <stdlib.h>

void write(void* ary, size_t size, size_t count, FILE* fp) {
    if (fwrite(ary, size, count, fp), ferror(fp) != 0) {
        perror("Write file");
        exit(1);
    }
}

void read(void* ary, size_t size, size_t count, FILE* fp) {
    if (fread(ary, size, count, fp), ferror(fp) != 0) {
        perror("Read File");
        exit(1);
    }
}

int main() {
    int a[] = {0,1,2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    FILE *fp = fopen("./a.bin", "wb");
    if (fp == NULL) {
        perror("open file");
        exit(1);
    }
    write(a, sizeof a[0], 3, fp);
    write(b, sizeof b[0], 4, fp);
    write(c, sizeof c[0], 3, fp);
    fclose(fp);

    int ra[3] = {0};
    char rb[4] = {0};
    float rc[3] = {0};

    FILE *fp2 = fopen("./a.bin", "rb");
    if (fp2 == NULL) {
        perror("open file");
        exit(1);
    }
    read(ra, sizeof ra[0], 3, fp2);
    read(rb, sizeof rb[0], 4, fp2);
    read(rc, sizeof rc[0], 3, fp2);

    printf("%d %d %d\n", ra[0], ra[1], ra[2]);
    printf("%c %c %c\n", rb[0], rb[1], rb[2]);
    printf("%f %f %f\n", rc[0], rc[1], rc[2]);
}