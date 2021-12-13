#include<stdio.h>
#include<math.h>
main()
{
	float x1,x2,y1,y2,k;
	printf("enter x1 value");
	scanf("%f",&x1);
	printf("enter x2 value");
	scanf("%f",&x2);
	printf("enter y1 value");
	scanf("%f",&y1);
	printf("enter y2 value");
	scanf("%f",&y2);
	k=sqrt((x2=x1)*(x2-x1)+(y2-y1)*(y2-y1));
	printf("length is %d",k);
	
}

