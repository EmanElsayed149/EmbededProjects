#include <stdio.h>

int main()
{
	char character ;
	printf("Enter an alphabet: ");  fflush(stdout);
	scanf("%c",&character);
	if(character == 'a' || character == 'e' || character == 'o' || character == 'i' || character =='u' || character == 'A' || character == 'E' || character == 'O' || character == 'I' || character =='U')
	
	{
		printf("%c is vowel \n",character);
			
	}
	else{
		printf("%c is consonent\n",character);
	}
}