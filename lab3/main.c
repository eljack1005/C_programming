#include <stdio.h>
#include <stdlib.h>
 int arr[5]={0,0,0,0,0};
 int grades[2][3]={{0,0,0},{0,0,0}};
char choice;
char test;
int main()
{
firstTask();
return 0;
 }

void firstTask(){
    system("clear");
    printf("\t ** array manipulation **\n");
    printf("\t ________________\n");
    printf("\t a) enter 5 numbers of single array \n ");
    printf("\t b) display the array elements \n ");
    printf("\t c) display min, max, sum and average \n ");
    printf("\t d) display reversed array \n ");
    printf("\t e) enter grade for 2 students in c , os , n + display \n ");
    printf("\t f) display each students grade \n ");
    printf("\t g) display avg of each course \n ");
    printf("\t h) **bonus** rotate \n ");
    printf("\t press x to exit ");

    printf("enter your choice:\n");
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
    firstTask();
    break;

case 'd':
    choiceD();
    firstTask();
    break;

case 'e':
    choiceE();
    firstTask();
    break;

case 'f':
    choiceF();
    firstTask();
    break;

case 'g':
    choiceG();
    firstTask();
    break;

case 'h':
    choiceH();
    firstTask();
    break;

case 'x':
    printf("thanks for your time");
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
    for(int i=0 ; i<5 ; i++){
        printf("Enter element number %d: \n", i+1);
        scanf(" %d",&arr[i]);
    }
    printf("you entered 5 elements successfully press any key to return");
    scanf(" %c",&test);
    return;
}

void choiceB(){
     system("clear");
    for(int i=0 ; i<5 ; i++){
        printf("element number %d = %d \n", i+1 , arr[i]);
    }
    scanf(" %c",&test);
    return;
}

void choiceC(){
     system("clear");
    int sum = 0, max=arr[0] , min = arr[0];
    float avg;
    for(int i=0 ; i<5 ; i++){
        sum +=arr[i];
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }
    avg = sum/5;
         printf("max = %d \n", max);
         printf("min = %d \n", min);
         printf("sum = %d \n", sum);
         printf("avg = %f \n", avg);

    scanf(" %c",&test);
    return;
}

void choiceD(){
     system("clear");
    for(int i=4 ; i>=0 ; i--){
        printf("element number %d = %d \n", i+1 , arr[i]);
    }
    scanf(" %c",&test);
    return;
}
void choiceE(){
     system("clear");
     int studentOneSum = 0 , studentTwoSum = 0;
     printf("enter first student c, os and cn grades in order \n");
     for(int i=0 ; i<3;i++){
     scanf(" %d",&grades[0][i]);
     studentOneSum+=grades[0][i];
     }

      printf("enter second student c, os and cn grades in order \n");
      for(int i=0 ; i<3;i++){
      scanf(" %d",&grades[1][i]);
      studentTwoSum+=grades[1][i];
     }
     printf("student 1 total grades = %d \n",studentOneSum);
     printf("student 2 total grades = %d \n",studentTwoSum);
    scanf(" %c",&test);
    return;
}
void choiceF(){
     system("clear");
     printf(" \t\t c\t\t os\t\t cn \n");
     printf("student 1 \t");
    for(int i=0 ; i<3 ; i++){
        printf(" %d\t\t", grades[0][i]);
    }
    printf("\nstudent 2 \t");
    for(int i=0 ; i<3 ; i++){
        printf(" %d\t\t", grades[1][i]);
    }
    scanf(" %c",&test);
    return;
}
void choiceG(){
    //misread the requirement ***************
    int sum1 =0, sum2 =0;
     system("clear");
     for(int i=0 ; i<3 ; i++){
        sum1 +=grades[0][i];
    }
    for(int i=0 ; i<3 ; i++){
        sum2 +=grades[1][i];
    }
    printf("first student avg = %f \n",(float)sum1/3);
    printf("first student avg = %f",(float)sum2/3);
    scanf(" %c",&test);
    return;
}

void choiceH(){
        printf("the array before rotation \n");
   for(int i=0 ; i<5;i++){
    printf(" %d ", arr[i]);
   }

int temp = arr[4];
    for (int i = 4; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    printf("\nthe array after rotation \n");
   for(int i=0 ; i<5;i++){
    printf(" %d ", arr[i]);
   }
   scanf(" %c",&test);
    return;
}
