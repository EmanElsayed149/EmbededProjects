#include <stdio.h>
#include <string.h>
int main()
{
    char string[20],ch;
    int fre=0;
    printf("Enter yout string: ");
    fgets(string,20,stdin);
    printf("Enter the character to find frequency: ");   fflush(stdout);
    scanf("%c",&ch);
    if(ch > 'A' && ch <'Z')
    {
        //convert it to small to count frequency of character whatever it 's capital or small
        ch = ch + ('a' - 'A');
    }
    for (int i=0; string[i]!='\0'; i++) {
        if(ch > 'A' && ch <'Z')
        {
            //convert it to small to count frequency of character whatever it 's capital or small
            string[i] = string[i] + ('a' - 'A');
        }
        if(string[i]==ch)
        {
            fre ++;
        }
    
    }
    printf("frequency of %c : %d\n",ch,fre);

}