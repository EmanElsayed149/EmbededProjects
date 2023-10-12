#include <stdio.h>
int main()
{
    int array[20];
    int n,element;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nEnter element to be searched: ");
    scanf("%d",&element);
    int i;
    for(i=0;i<n;i++)
    {
        if(array[i]==element)
        {
            printf("element is found at location %d\n",i+1);
            break;
        }
    }
    if(i==n)
        printf("element not found\n");
}