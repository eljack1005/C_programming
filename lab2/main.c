#include <stdio.h>
#include <stdlib.h>
void gotoxy(int x, int y)
{
    // Move cursor to row y, column x
    printf("\033[%d;%dH", y, x);
}
char test;
char choice;
void firstTask();
void choiceB();
void choiceA();
void choiceC();



void secondTask();

void thirdTask();

void forthTask();

int main()
{
   //firstTask();
   //secondTask();
   // thirdTask();
    forthTask();

    return 0;
}
void firstTask(){
    system("clear");
    printf("\t ** Main Menu **\n");
    printf("\t ________________\n");
    printf("\t a) Say Good Morning \n ");
    printf("\t b) Say Good Evening \n ");
    printf("\t c) Exit program \n ");
    printf("    enter your choice: ");
    scanf(" %c",&choice);
    afterChoice(choice);


}
void afterChoice(char choice){
switch (choice){
case 'a':
    choiceA();
    firstTask();
    break;

case 'b':
    choiceB();
    firstTask();
    break;

case 'c':
    choiceC();
    break;

default:
    system("clear");
    printf("\t  enter a valid value \n ");
    scanf(" %c",&test);

    firstTask();
break;
}
return;
}
void choiceA(){
     system("clear");
    printf("\t  Good Morning \n ");
    scanf(" %c",&test);
    return;
}

void choiceB(){
     system("clear");
    printf("\t  Good afternon \n ");
    scanf(" %c",&test);
    return;
}

void choiceC(){
     system("clear");
    printf("\t  Good bye \n ");
    scanf(" %c",&test);
    return;
}


void secondTask(){
    int sum=0 , currentNumber;
    do{
        printf("enter your current number \n");
        scanf("%d",&currentNumber);
        sum+=currentNumber;
    }while(sum<100);
    printf("the number exceeded 100 and now equals %d",sum);
    scanf(" %c",&test);
    return;
}







void thirdTask(){
  int row, col, size, i;

    printf("Input odd square size: ");
    scanf("%d", &size);

    row = 1;
    col = size / 2 + 1;

    for(i = 1; i <= size * size; i++)
    {
        gotoxy(col * 3 + 1, row * 3 + 1);
        printf("%d", i);
        fflush(stdout); // Important in Linux console output

        if(i % size)
        {
            row--;
            col--;
        }
        else
        {
            row++;
        }

        if(col < 1)
            col = size;
        if(col > size)
            col = 1;

        if(row < 1)
            row = size;
        if(row > size)
            row = 1;
    }

    // Move cursor down after drawing
    gotoxy(1, size * 3 + 3);
    printf("\n");

    return;
}


void forthTask(){
    int firstNum, secondNum , result;
    char theOperator;
    theBegining:
    printf("enter the first number\n");
    scanf(" %d",&firstNum);
    printf("enter the second number\n");
    scanf("%d",&secondNum);
    printf("enter your operator\n");
    scanf(" %c",&theOperator);

    switch(theOperator){
    case '+':
    result = firstNum+secondNum;
    printf("the result = %d",result);
    break;
    case '-':
            result = firstNum-secondNum;
        printf("the result = %d",result);

    break;
    case '*':
            result = firstNum*secondNum;
        printf("the result = %d",result);

    break;
    case '/':
            result = firstNum/secondNum;
        printf("the result = %d",result);

    break;
    default:
    printf("invalid operator");
    break;
    }
    char yesORno;
    printf("\ndo you wish to continue Y/N ?\n");
    scanf(" %c",&yesORno);
    if(yesORno == 'y' || yesORno == 'y'){
    goto theBegining;
    }
else{
    return;
}}



