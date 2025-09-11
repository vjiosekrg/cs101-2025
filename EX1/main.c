#include <stdio.h>

int main() {
    printf("\t\t2025 9月\n");
    printf("日\t一\t二\t三\t四\t五\t六\n");
    printf("\033[1;34m31\033[0m"); // Day 31 in blue, then reset color
    printf("\033[1;36m\t1\t2\t3\t4\t5\t6\033[0m\n");
    printf("\033[1;36m7\t8\t9\t10\t11\t12\t13\n");
    printf("\033[1;36m14\t15\t16\t17\t18\t19\t20\n");
    printf("\033[1;36m21\t22\t23\t24\t25\t26\t27\n");
    printf("\033[1;36m28\t29\t30\t");
    printf("\033[1;34m1\t2\t3\t4\033[0m\n");

    return 0;
}