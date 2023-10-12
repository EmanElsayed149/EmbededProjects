#include <stdio.h>

int main()
{
	float number1,number2,number3 ;
	printf("enter three numbers:\n");  fflush(stdout);
	scanf("%f %f %f",&number1,&number2,&number3);
	if(number1 > number2)
	{
		if(number1 > number3)
		{
			printf("largest number = %f \n",number1);
		}
		else{
			printf("largest number = %f \n",number3);
		}
	}
	else{
		if(number2 > number3)
		{
			printf("largest number = %f \n",number2);
		}
		else{
			printf("largest number = %f \n",number3);
		}
	}
}