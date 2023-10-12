#include <stdio.h>

int main()
{
	char character ;
	printf("Enter a Character: ");  fflush(stdout);
	scanf("%c",&character);
	printf("ASCI value of %c = %d",character,character);
}