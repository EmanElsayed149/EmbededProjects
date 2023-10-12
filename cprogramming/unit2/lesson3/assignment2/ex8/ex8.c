#include <stdio.h>

int main()
{
	char op;
	float num1,num2,res;
	printf("Enter operator either + or - or * or /\n");   fflush(stdout);
	scanf("%c",&op);
	printf("Enter two operands: \n");                      fflush(stdout);
	scanf("%f %f",&num1,&num2);
	switch(op)
	{
		case '+' :
		    res = num1 + num2;
		    printf("%f + %f = %f\n",num1,num2,res);
			break;
		case '-' :
		    res = num1 - num2;
			printf("%f - %f = %f\n",num1,num2,res);
			break;
		case '*':
		    res = num1 * num2;
			printf("%f * %f = %f\n",num1,num2,res);
			break;
		case '/':
		    res = num1 / num2;
			printf("%f / %f = %f\n",num1,num2,res);
			break;
	}
	
	
	
}