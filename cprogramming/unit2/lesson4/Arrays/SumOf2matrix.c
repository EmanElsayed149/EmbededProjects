#include <stdio.h>
int main()
{
    float matrix1[2][2],matrix2[2][2],matrix3[2][2],temp;
    printf("enter elements of 1st matrix\n");
    for(int i =0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("enter element%d%d: ",i+1,j+1);   fflush(stdout);
            scanf("%f",&matrix1[i][j]);
        }
    }
    printf("enter elements of 2nd matrix\n");
    for(int i =0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("enter element%d%d: ",i+1,j+1);   fflush(stdout);
            scanf("%f",&matrix2[i][j]);
        }
    }
    printf("Sum of 2 matrixes is :\n");
    for(int i =0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            temp = matrix1[i][j] + matrix2[i][j];
            printf("%.2f   ",temp);   fflush(stdout);
        }
        printf("\n");
    }

}