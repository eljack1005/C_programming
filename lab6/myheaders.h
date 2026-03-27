#ifndef MYHEADERS_H_INCLUDED
#define MYHEADERS_H_INCLUDED
#include <stdio.h>

struct employee {
    int code;
    char name[31];
    float salary;
    int overTime;
    float deduction;
    int age;
    int exists;
};

void textattr(int attr);
void gotoxy(int x, int y);
int getch(void);
void homeFunction();
void changetheHighlight(int current);
void afterEnter(int state);
void getEmployee();
void drawConsole(int empNum ,struct employee *employees);
void handleNameInput(int empNum, struct employee *employees);
void displayInfo(struct employee *employees , int size);


#endif // MYHEADERS_H_INCLUDED
