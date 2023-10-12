#include <stdio.h>

int main()
{
	int n,fact=1;
	printf("enter an intger: ");  fflush(stdout);
	scanf("%d",&n);
	if(n <0 )
	{
		printf("Error !!! factorial of negatine number doesn't exist\n");
	}
	else{
		for(int i=1;i<=n ;i++)
		{
			fact*=i;
		}
		printf("factorial = %d\n",fact);
	}
	
	
}