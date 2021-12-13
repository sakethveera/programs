#include <stdio.h>
 
int main()
{
    int a;
     
    printf("Enter a positive integer number");
    scanf("%d",&a);
     
    switch(a%2)
    {
        case 0:
            printf("%d is an EVEN a\n",a);
            break;
        case 1:
            printf("%d is an ODD a\n",a);
            break;
    }
     
}
