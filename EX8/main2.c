#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int compare_integers(const void *a, const void *b) {
    int val_a = *(const int*)a;
    int val_b = *(const int*)b;
    
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
    
}

void sort(int *ary, int n) {
    qsort(ary, n, sizeof(int), compare_integers);
}

int get_count() {
    FILE *fp = fopen("./counter.bin", "r");
    if (fp == NULL) {
        return 1;
    }
    int ary[1];
    fread(ary, sizeof (int), 1, fp);
    return ary[0];
}

void set_count(int n) {
    FILE *fp = fopen("./counter.bin", "w");
    int ary[1] = {n};
    fwrite(ary, sizeof (int), 1, fp);
}

void print_ctime_no_newline(FILE *fp) {
    time_t tim = time(NULL);
    char *timestamp = ctime(&tim);
    
    // 1. Check if the string is valid and long enough to contain a newline
    // The typical ctime string length is 26 characters (e.g., "Wed May 15 10:15:30 2024\n\0")
    if (timestamp != NULL && strlen(timestamp) > 0) {
        
        // 2. Locate the last character (which is the newline \n)
        size_t len = strlen(timestamp);
        
        // 3. Check if the last character is indeed a newline and replace it with a null terminator.
        if (timestamp[len - 1] == '\n') {
            timestamp[len - 1] = '\0';
        }
    }

    // Now, print the formatted header using the modified string
    fprintf(fp, "==");
    fprintf(fp, "%s", timestamp); // Use %s for the modified string
    fprintf(fp, "==\n");
}

int print_table(int cnt) {
    int n = 5;
    printf("歡迎光臨長庚樂透彩買系統\n");
    printf("請問您要買幾組樂透\n");
        
    scanf("%d", &n);  //從輸入讀取要產生的樂透組數
    srand(time(NULL));  //固定亂數種子，否則 Judge 結果會不同
    //開啟作答 % 69 + 1


    char filename_buffer[1024]; 

    // 2. Use snprintf to format the string into the buffer.
    // The format string is "./lotto%05d.txt", which pads the integer 'count' 
    // with leading zeros up to 5 characters.
    snprintf(
        filename_buffer, 
        sizeof(filename_buffer), 
        "./lotto%05d.txt", 
        cnt
    );

    FILE * fp = fopen(filename_buffer, "w");
    int k;

    int lotto_cnt = 6;
    int lotto_col_cnt = 7;

    time_t tim = time(NULL);

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "========= No.%05d ========\n", cnt);
    print_ctime_no_newline(fp);
    for (int i=1;i<lotto_cnt;i++) {
        int lottos[lotto_col_cnt-1] = {};
        
        fprintf(fp, "[%d]:", i);
        bool ary[100] = {0};
        for (int j=0;j<7;j++) {
            if (n >= i) {
                while(ary[k = rand() % 69+1]);
                ary[k] = true;
                lottos[j] = k;
                //fprintf(fp, " %02d", k);
            }
            else {
                fprintf(fp, " __");
            }
        }

        if (n >= i) {
            sort(lottos, 7);
            for (int j=0;j<7;j++) {
                fprintf(fp, " %02d", lottos[j]);
            }
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("已為您購買的 %d 組樂透組合輸出至 %.1024s\n", n, filename_buffer);
    return 0;
}

int main() {
    int n = get_count();
    print_table(n);
    set_count(n+1);
    return 0;
}