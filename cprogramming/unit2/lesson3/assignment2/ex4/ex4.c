#include <stdio.h>

int main()
{
	float number1 ;
	printf("enter a number: \n");  fflush(stdout);
	scanf("%f",&number1);
	if(number1>0)
	{
		printf("%f is positive\n",number1);
	}else if(number1<0)
	{
		printf("%f is negetive\n",number1);
	}
	else{
		printf("you entered 0\n");
	}
}