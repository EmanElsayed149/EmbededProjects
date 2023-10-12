#include <stdio.h>

int main()
{
	float number1,number2,sum ;
	printf("enter two real numbers: \n");  fflush(stdout);
	scanf("%f %f",&number1,&number2);
	sum = number1+ number2;
	printf("sum: %f",sum);
}