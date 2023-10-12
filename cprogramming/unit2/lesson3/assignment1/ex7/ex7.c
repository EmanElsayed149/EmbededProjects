#include <stdio.h>

int main()
{
	int a,b;
	printf("enter value of a: ");  fflush(stdout);
	scanf("%d",&a);
	printf("enter value of b: ");  fflush(stdout);
	scanf("%d",&b);
	//to swap to numbers without temp variable
	a = a ^ b;
	b = a ^ b;    //b^b = 0            //a^b^b= a
	a = a ^ b;    
	printf("Afetr swapping , the value of a: %d\n",a);  fflush(stdout);
	printf("Afetr swapping , the value of b: %d\n",b);  fflush(stdout);
}