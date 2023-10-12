#include <stdio.h>

int main()
{
	int number ;
	printf("Enter number you want to check: ");   fflush(stdout);
	scanf("%d",&number);
	if(number%2==0)
	{
		printf("%d is Even\n",number);
	}
	else
	{
		printf("%d is Odd\n", number);
	}
}