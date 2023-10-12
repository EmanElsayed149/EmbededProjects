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
    //if you use scanf to input string print len not len-1 
    printf("length of string: %d\n",len-1);

}