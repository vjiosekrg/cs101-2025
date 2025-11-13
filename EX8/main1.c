#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define NUM_USER_PICKS 3
#define FILENAME "lotto00001.txt"


typedef struct {
    int column_num;
    int numbers[7]; 
    int count;      
} LottoColumn;


// Function to parse the file and fill the lotto_data array
int parse_lotto_file(LottoColumn lotto_data[], int max_columns) {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        perror("錯誤");
        return 0;
    }
    
    char line[MAX_LINE_LENGTH];
    int current_column = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        int col_num;
        if (sscanf(line, "[%d]:", &col_num) == 1) {
            if (current_column < max_columns) {
                lotto_data[current_column].column_num = col_num;
                lotto_data[current_column].count = 0;
                
                char *data_start = strchr(line, ':');
                if (data_start) {
                    data_start += 2; 
                    char *token = strtok(data_start, " \t\n");
                    int num_idx = 0;
                    
                    while (token != NULL && num_idx < 7) {
                        lotto_data[current_column].numbers[num_idx] = atoi(token);
                        num_idx++;
                        token = strtok(NULL, " \t\n");
                    }
                    lotto_data[current_column].count = num_idx;
                    current_column++;
                }
            }
        }
    }
    
    fclose(fp);
    return current_column;
}

int is_winning_number(int user_num, const LottoColumn *column) {
    for (int i = 0; i < column->count; i++) {
        if (user_num == column->numbers[i]) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    
    LottoColumn lotto_data[5]; 
    int total_columns = parse_lotto_file(lotto_data, 5);

    if (total_columns == 0) {
        printf("No lottery columns were parsed. Exiting.\n");
        return 1;
    }

    int user_picks[NUM_USER_PICKS];
    
    
    printf("請輸入中獎號碼三個: ", NUM_USER_PICKS);
    if (scanf("%d %d %d", &user_picks[0], &user_picks[1], &user_picks[2]) != NUM_USER_PICKS) {
        printf("無效輸入.\n");
        return 1;
    }

    printf("輸入中獎號碼為: %02d, %02d, %02d\n", user_picks[0], user_picks[1], user_picks[2]);

    // 3. Check for winning numbers
    printf("以下為中獎號碼\n");
    int won_any = 0;

    for (int i = 0; i < total_columns; i++) {
        int match_count = 0;
        
        for (int j = 0; j < NUM_USER_PICKS; j++) {
            if (is_winning_number(user_picks[j], &lotto_data[i])) {
                match_count++;
            }
        }

        // Print the lottery col if any number is won (match_count > 0)
        if (match_count > 0) {
            printf("[%d]: ", lotto_data[i].column_num);
            for(int k=0; k < lotto_data[i].count; k++) {
                printf("%02d ", lotto_data[i].numbers[k]);
            }
            printf("\n");
            won_any = 1;
        }
    }

    return 0;
}