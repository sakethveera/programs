#include<stdio.h>
int main()
{
    float principle , time , rateofinterest , simpleinterest ;
   printf("enter the value of principle amount");
   scanf("%f",&principle );
   printf("enter the value of time ");
   scanf("%f",&time);
   printf("enter the value of rate of interest");
   scanf("%f",&rateofinterest);
   simpleinterest = (principle *time*rateofinterest)/100;
   printf("value of simple interest is %f",simpleinterest);
   

}

