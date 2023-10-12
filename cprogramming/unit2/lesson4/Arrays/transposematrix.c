
#include <stdio.h>
int main()
{
    int rows,colomns;
    float matrix[5][5],transpose[5][5];
    printf("enter rows and colomns  of matrix\n");
    scanf("%d %d",&rows,&colomns);
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<colomns;j++)
        {
            printf("enter element%d%d: ",i+1,j+1);   fflush(stdout);
            scanf("%f",&matrix[i][j]);
        }
    }
    printf("entered matrix:\n");
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<colomns;j++)
        {
            printf("%.2f  ",matrix[i][j]);   fflush(stdout);
        }
        printf("\n");
    }
    printf("transpose of matrix is :\n");
    for(int i =0;i<colomns;i++)
    {
        for(int j=0;j<rows;j++)
        {
            printf("%.2f   ",matrix[j][i]);   fflush(stdout);
        }
        printf("\n");
    }

}