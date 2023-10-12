#include <stdio.h>

int main()
{
	int number1,number2,sum ;
	printf("enter two intgers: \n");  fflush(stdout);
	scanf("%d %d",&number1,&number2);
	sum = number1+ number2;
	printf("sum: %d",sum);
}