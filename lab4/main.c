#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
char arr1[41];
char fname[21];
char lname[21];
char fullName[42];
char choice[3][9]={{'1','new'},{'2','display'},{'3','end'}};
char cohice2[3]={'1','2','3'};

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
int main()
{
    //firstTask();
//secondTask();
  //thirdTask();
  fourthTask();
    return 0;
}


void firstTask(){
    int counter=0;
    char temp;
    printf("enter your name *max 20 char* ");
while(counter<20){
            temp = getch();
if(temp == 10){
    printf("\nyour name is %s",arr1);
    getch();
    break;
}
else if(temp == 8 || temp == 127){
if(counter > 0){
printf("\b \b");
arr1[--counter] = "";
}
}
else{
    arr1[counter++] = temp;
    printf("%c",arr1[counter-1]);
    fflush(stdout);
}
}
return;
}




void secondTask(){
int counter = 0;
char temp;
printf("enter your first name *max 20 letters: ");

while(counter<20){
temp = getch();
if(temp == 10){
    printf("\n");
    getSecondName();
    break;
}
else if(temp == 8 || temp == 127){
if(counter > 0){
printf("\b \b");
fname[--counter] = "";
}
}
else{
    if(counter<19){
    fname[counter++] = temp;
    printf("%c",fname[counter-1]);
    fflush(stdout);
    }
}
}


return;
}

void getSecondName(){
int counter = 0;
char temp;
printf("enter your last name *max 20 letters: ");

while(counter<20){
temp = getch();
if(temp == 10){
    getFullname();
    break;
}
else if(temp == 8 || temp == 127){
if(counter > 0){
printf("\b \b");
lname[--counter] = '\0';
}
}
else{
    if(counter<19){
    lname[counter++] = temp;
    printf("%c",lname[counter-1]);
    fflush(stdout);
    }
}
}
}

void getFullname(){
     strcat(fullName, fname);
    strcat(fullName, " ");
    strcat(fullName, lname);

    printf("\nyour full name is %s", fullName);
    return;
}


void thirdTask(){
char temp;
while(1==1){

    temp = getch();
    if(temp == 27){
       temp = getchar();
            if (temp == '[') {
                temp = getchar();
                  if(temp == 'A')
                    printf("up arrow");
                  else if(temp == 'B')
                    printf("down arrow");
                  else if(temp == 'H')
                    printf("home");
                 else if(temp == 'F')
                    printf("down");
                 else if(temp == '5'){
                    getchar();
                    printf("page up");}
                 else if(temp == '6'){
                    getchar();
                    printf("page down");}

    }else{
    break;
    }



}else{
printf("%d",temp);
}
printf("\t");
}

}

void fourthTask(){
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
printf("\n\n\n\t\t\t you pressed new");
getch();
fourthTask();
    break;

case 1:
printf("\n\n\n\t\t\t you pressed display");
getch();
fourthTask();
    break;

case 2:
printf("\n\n\n\t\t\t you pressed end thanks for using the program");
getch();
exit(EXIT_SUCCESS);
    break;
}

return;
}
