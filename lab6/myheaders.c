#include "myheaders.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>


struct employee emp[10];
int size = sizeof emp / sizeof emp[0];

void gotoxy(int x, int y)
{
    // Move cursor to row y, column x
    printf("\033[%d;%dH", y, x);
}

void textattr(int attr) {
    printf("\033[%dm", attr);
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
void homeFunction(){
char temp;
int currentPlace = 0;
int flag = 0;
changetheHighlight(0);

while(flag==0){
    temp = getch();
    if(temp == 27){
       temp = getchar();
            if (temp == '[') {
                temp = getchar();
                  if(temp == 'A'){
                    if(currentPlace==0){
                        currentPlace = 2;
                        changetheHighlight(currentPlace);
                    }
                    else{
                       changetheHighlight(--currentPlace);

                    }
                  }
                  else if(temp == 'B'){
                    if(currentPlace==2){
                        currentPlace = 0;
                        changetheHighlight(currentPlace);

                    }
                    else{
                        changetheHighlight(++currentPlace);
                    }
                  }
}
textattr(0);

}else if(temp =='\n'){
    afterEnter(currentPlace);
}
}
}




void changetheHighlight(int current){
system("clear");
switch(current){
case 0:
    textattr(31);
printf("\n\t\t ** Main Menu **");
printf("\n\t\t ________________");
printf("\n\t\t \033[44mnew\033[0m");
textattr(33);
printf("\n\t\t display");
printf("\n\t\t end\n");
textattr(0);

    break;

case 1:
textattr(31);
printf("\n\t\t ** Main Menu **");
printf("\n\t\t ________________");
textattr(33);
printf("\n\t\t new");
textattr(31);
printf("\n\t\t \033[44mdisplay\033[0m");
textattr(33);
printf("\n\t\t end\n");
textattr(0);

    break;

case 2:
textattr(31);
printf("\n\t\t ** Main Menu **");
printf("\n\t\t ________________");
textattr(33);
printf("\n\t\t new");
printf("\n\t\t display");
textattr(31);
printf("\n\t\t \033[44mend\033[0m\n");
textattr(0);

    break;
}

return;
}
void afterEnter(int state){
    system("clear");
switch(state){
case 0:
getEmployee();
    break;

case 1:
displayInfo(emp, size);
    break;

case 2:
printf("\n\n\n\t\t\t you pressed end thanks for using the program");
getch();
exit(EXIT_SUCCESS);
    break;
}

return;
}

void getEmployee(){
    int flag = 0;
    int empNum = 0;
    while (flag == 0){
        system("clear");
        printf("enter employee number from 1 to 10 (0 to go back): ");
        scanf(" %d",&empNum);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if(empNum>0 && empNum<11){
        emp[empNum-1].exists = 1;
        drawConsole(empNum-1 , emp);
        }
        else if(empNum == 0){
         homeFunction();
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
homeFunction();

}

