#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
void gotoxy(int x, int y)
{
    // Move cursor to row y, column x
    printf("\033[%d;%dH", y, x);
}
int getch(void){
    struct termios old, new;
    tcgetattr(STDIN_FILENO, &old);
    new = old;
    new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return ch;
}
struct employee{
    int code;
    char name[31];
    float salary;
    int overTime;
    float deduction;
    int age;
    int exists;
    };
int main()
{
    //firstTask();
   // secondTask();
    thirdTask();
    return 0;
}
void firstTask(){



    struct employee e1;

    printf("enter employee's code\n");
    scanf(" %d",&e1.code);
printf("enter employee's name\n");
    scanf(" %s",e1.name);
printf("enter employee's salary\n");
    scanf(" %d",&e1.salary);


    printf("\nEmployee data\nName: %s \nCode: %d \nSalary: %d",e1.name,e1.code,e1.salary);
}





void secondTask(){
    struct employee emp[5];
    for(int i=0;i<5;i++){
        printf("enter employee number %d code\n",i+1);
    scanf(" %d",&emp[i].code);
printf("enter employee's number %d name\n",i+1);
    scanf(" %s",&emp[i].name);
printf("enter employee's number %d salary\n",i+1);
    scanf(" %d",&emp[i].salary);

    }
        for(int i=0;i<5;i++){
            printf("\nEmployee number %d data\nName: %s \nCode: %d \nSalary: %d\n",i+1,emp[i].name,emp[i].code,emp[i].salary);

        }

}







void thirdTask(){
    struct employee emp[10];
    int flag = 0;
    int empNum = 0;
    int size = sizeof emp / sizeof emp[0];
    while (flag == 0){
        system("clear");
        printf("enter employee number from 1 to 10 (0 to exit): ");
        scanf(" %d",&empNum);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if(empNum>0 && empNum<11){
        emp[empNum-1].exists = 1;
        drawConsole(empNum-1 , emp);
        }
        else if(empNum == 0){
        displayInfo(emp,size);
        }
        else{
            system("clear");
            printf("Enter a valid number ");
            getch();
        }
    }
}


void drawConsole(int empNum ,struct employee *employees){
    system("clear");
    gotoxy(5 , 2);
    printf("code: ");
    gotoxy(5 , 4);
    printf("name: ");
    gotoxy(5 , 6);
    printf("age: ");
    gotoxy(5 , 8);
    printf("Over Time: ");
    gotoxy(45 , 6);
    printf("Salary: ");
    gotoxy(45 , 8);
    printf("deduction: ");
    gotoxy(10 , 2);
    scanf(" %d",&employees[empNum].code);
    gotoxy(10 , 4);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    handleNameInput(empNum ,employees);
    gotoxy(9 , 6);
    scanf(" %d",&employees[empNum].age);
    gotoxy(15 , 8);
    scanf(" %d",&employees[empNum].overTime);
    gotoxy(52 , 6);
    scanf(" %f",&employees[empNum].salary);
    gotoxy(55 , 8);
    scanf(" %f",&employees[empNum].deduction);
    getch();
}
void handleNameInput(int empNum, struct employee *employees) {
    int counter = 0;
    char temp;

    while (counter < 30) {
        temp = getch();

        if (temp == 10) {
            break;
        }
        else if (temp == 8 || temp == 127) {
            if (counter > 0) {
                printf("\b \b");
                employees[empNum].name[--counter] = '\0';
            }
        }
        else {
            if (counter < 29) {
                employees[empNum].name[counter++] = temp;
                printf("%c", temp);
            }
        }
    }

    employees[empNum].name[counter] = '\0';
}

void displayInfo(struct employee *employees , int size){
for(int i = 0 ; i < size ; i++){
    if(employees[i].exists == 1){
      system("clear");
    gotoxy(5 , 2);
    printf("code: ");
    gotoxy(5 , 4);
    printf("name: ");
    gotoxy(5 , 6);
    printf("age: ");
    gotoxy(5 , 8);
    printf("Over Time: ");
    gotoxy(45 , 6);
    printf("Salary: ");
    gotoxy(45 , 8);
    printf("deduction: ");
    gotoxy(10 , 2);
    printf(" %d",employees[i].code);
    gotoxy(10 , 4);
    printf(" %s",employees[i].name);
    gotoxy(9 , 6);
    printf(" %d",employees[i].age);
    gotoxy(15 , 8);
    printf(" %d",employees[i].overTime);
    gotoxy(52 , 6);
    printf(" %f",employees[i].salary);
    gotoxy(55 , 8);
    printf(" %f",employees[i].deduction);
    gotoxy(5 , 10);
    printf("net salary:%f ",employees[i].salary + employees[i].overTime*20 - employees[i].deduction);
    gotoxy(5 , 14);
    printf("press any key to continue ");
    getch();
    }



}
 system("clear");
    printf("thank you for your attention ");
    getch();
    exit(0);
}
