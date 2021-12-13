#include<stdio.h>
main ()
  {
    char ch;
  	int Quantity,bill;
  	printf("burger-B,sandwich-S,frenchfries-F,pizza-P");
  	
  	scanf("%c",&ch);
  	
  	switch(ch)
  	{
  		case 'B':printf("ordered for burger");
  		          printf("enter the Quantity");
  		          scanf("%d",&Quantity);
  		          bill=Quantity*200;
  		          break;
        case 'S':printf("ordered for sandwich");
  		          printf("enter the Quantity");
  		          scanf("%d",&Quantity);
  		          bill=Quantity*150;
  		          
  		          break;
  		case 'F':printf("ordered for frenchfries");
  		          printf("enter the Quantity");
  		          scanf("%d",&Quantity);
  		          bill=Quantity*50;
  		          break;
  		case 'P':printf("ordered for pizza");
  		          printf("enter the Quantity");
  		          scanf("%d",&Quantity);
  		          bill=Quantity*500;
  		          break;
						 
    }
    printf("total bill is %d",bill);
    	switch(ch)
  	{
  		case 'B':printf("ordered for burger");
  		          printf("enter the Quantity");
  		          scanf("%d",&Quantity);
  		          bill=Quantity*200;
  		          break;
        case 'S':printf("ordered for sandwich");
  		          printf("enter the Quantity");
  		          scanf("%d",&Quantity);
  		          bill=Quantity*150;
  		          
  		          break;
  		case 'F':printf("ordered for frenchfries");
  		          printf("enter the Quantity");
  		          scanf("%d",&Quantity);
  		          bill=Quantity*50;
  		          break;
  		case 'P':printf("ordered for pizza");
  		          printf("enter the Quantity");
  		          scanf("%d",&Quantity);
  		          bill=Quantity*500;
  		          break;
						 
    }
    printf("total bill is %d",bill);
 }
