#include <stdio.h>

int main()
{
	int a,b,temp;
	printf("enter value of a: ");  fflush(stdout);
	scanf("%d",&a);
	printf("enter value of b: ");  fflush(stdout);
	scanf("%d",&b);
	//to swap to numbers with temp variable
	temp = a;
	a= b;
	b= temp;    
	printf("Afetr swapping , the value of a: %d\n",a);  fflush(stdout);
	printf("Afetr swapping , the value of b: %d\n",b);  fflush(stdout);
}