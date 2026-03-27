#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y , sum=0;
    float avg=0;
printf("Enter two numbers please .\n ");
scanf("%d" , &x);
scanf("%d" , &y);
sum = x+y;
avg=(float)sum/2;
printf("the sum of the two numbers is %d \n ", sum);
printf("the avg of the two numbers is %f \n ", avg);
scanf("%d" , &y);

    return 0;
}
/*
int main()
{
int n;
char c;
printf("enter the char\n");
scanf("%c" , &c);
printf("enter the number\n");
scanf("%d" , &n);
printf("the char of the number %d is %c \n",n ,n);
printf("the ASCII code for the char %c is %d",c ,c);


scanf("%d" , &n);

     return 0;
}
*/
/*
int main()
{
    int x ;
printf("Enter number please .\n ");
scanf("%d" , &x);
printf("before pre increament %d \n",x);
printf("pre increament %d \n",++x);
printf("post increament %d \n",x++);
printf("after post increament %d \n", x);

scanf("%d" , &x);


       return 0;
}
*/

