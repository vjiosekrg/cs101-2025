#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
    int id;
    char name[10];
    int age;
    float salary;
} employee_t;

void emp_info(employee_t emp) {
    printf("employee id = %d\n", emp.id);
    printf("employee name = %.10s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %f\n", emp.salary);

}

int emp_average_age(int n, employee_t emp[n]) {
    int k = 0;
    for (employee_t *p = emp; p - emp < n; p++) {
        k += emp->age;
    }
    return emp->age / n;
}

void emp_writefile(employee_t emp[], int n) {
    FILE *fp = fopen("./employee.bin", "wb");
    fwrite(emp, sizeof (employee_t), n, fp);
    fclose(fp);
}

void emp_readfile(employee_t emp[], int n) { 
    FILE *fp = fopen("./employee.bin", "rb");
    for (employee_t *i = emp; i-emp <n; i++) {
        fread(i, sizeof (employee_t), 1, fp);
    }
    fclose(fp);
}

int main() {

    employee_t emp[] = {
        {1, "heyh", 20, 2.2e4f},
        {2, "chrome", 40, 4e6f},
        {3, "edge", 5, 2e6f}
    };

    employee_t read_emp[3] = {0};

    emp_writefile(emp, 3);
    emp_readfile(read_emp, 3);
    for (int i=0;i<3;i++) {
        emp_info(read_emp[i]);
    }
    printf("Average age: %d\n", emp_average_age(3, read_emp));
    
}
