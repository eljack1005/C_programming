#include <stdio.h>
#include <stdlib.h>

void swapInts() {
    int a, b;
    printf("enter a: ");
    scanf("%d", &a);
    printf("enter b: ");
    scanf("%d", &b);

    int *p1 = &a, *p2 = &b;

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("\nafter swap: a = %d, b = %d\n", a, b);
}


void arrayIO() {
    int size;
    printf("enter array size: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    int *ptr = arr;

    printf("enter %d numbers:\n", size);

    for (int i = 0; i < size; i++)
        scanf("%d", ptr + i);

    printf("\nYou entered:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", *(ptr + i));

    printf("\n");
    free(arr);
}


struct employee {
    int id;
    char name[30];
    float salary;
};

void employeeSystem() {
    int n, choice, index = 0;

    printf("enter number of employees: ");
    scanf("%d", &n);

    struct employee *arr = malloc(n * sizeof(struct employee));

    while (1) {
        printf("\n   employee menu   \n");
        printf("1) add Employee\n");
        printf("2) display Employees\n");
        printf("3) exit to Main Menu\n");
        printf("choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (index < n) {
                printf("enter ID: ");
                scanf("%d", &arr[index].id);

                printf("enter Name: ");
                scanf("%s", arr[index].name);

                printf("enter Salary: ");
                scanf("%f", &arr[index].salary);

                index++;
            } else {
                printf("employee array is full\n");
            }
        }

        else if (choice == 2) {
            for (int i = 0; i < index; i++) {
                printf("\nemployee %d\n", i + 1);
                printf("ID: %d\n", arr[i].id);
                printf("name: %s\n", arr[i].name);
                printf("salary: %.2f\n", arr[i].salary);
            }
        }

        else if (choice == 3) {
            free(arr);
            return;
        }

        else {
            printf("invalid choice\n");
        }
    }
}


void pointerToPointer() {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("x = %d\n", x);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);

    **pp = 50;

    printf("New value of x = %d\n", x);
}


int main() {
    int choice;

    while (1) {
        printf("\n      MAIN MENU        \n");
        printf("1) swap Two Integers\n");
        printf("2) array Input/Output Using Pointers\n");
        printf("3) employee System (Dynamic Allocation)\n");
        printf("4) pointer to Pointer Example\n");
        printf("5) exit\n");
        printf("choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                swapInts();
                break;
            case 2:
                arrayIO();
                break;
            case 3:
                employeeSystem();
                break;
            case 4:
                pointerToPointer();
                break;
            case 5:
                printf("exiting  \n");
                return 0;
            default: printf("invalid choice\n");
        }
    }
}
