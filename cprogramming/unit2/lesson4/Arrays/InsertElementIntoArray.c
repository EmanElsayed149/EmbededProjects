#include <stdio.h>
int main()
{
    int array[20];
    int n,location,newelement;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nEnter element to be inserted: ");
    scanf("%d",&newelement);
    printf("Enter its location: ");
    scanf("%d",&location);
    for(int i=n;i>=location;i--)
    {
        array[i]=array[i-1];
    }
    array[location-1]=newelement;
    for(int i=0;i<n+1;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}