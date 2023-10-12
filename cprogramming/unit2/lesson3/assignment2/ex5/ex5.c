#include <stdio.h>

int main()
{
	char character ;
	printf("Enter a Character: ");  fflush(stdout);
	scanf("%c",&character);
	if((character >= 65 && character <=90) || (character >= 97 && character <=122))
	{
		printf("%c is alphabet",character);
	}else{
		printf("%c is not alphabet",character);
	}
	
}