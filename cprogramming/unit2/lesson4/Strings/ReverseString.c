#include <stdio.h>
#include <string.h>
int main()
{
    char string[20];
    int len=0;
    printf("Enter yout string: ");
    fgets(string,20,stdin);
    for (int i=0; string[i]!=0; i++) {
         len++;
    }
    for (int i=len-2; i>=0; i--) {
        printf("%c",string[i]);
    }
    printf("\n");
    

}