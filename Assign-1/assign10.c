//Program to print Pascal's triangle

#include <stdio.h>

int main()
{
    int row,c=1,a,i,j;
    printf("How many rows of patterns are you looking for: ");
    scanf("%d",&row);
    for(i=0;i<=row;i++)
    {
        for(a=1;a<=row-i;a++)
        {
            printf("  ");
        }
            for(j=0;j<=i;j++)
            {
                if (j==0||i==0)
                {
                    c=1;
                }
                else
                {
                    c=c*(i-j+1)/j;
                    printf("%4d",c);
                }
            }
            printf("\n");
        
    }
    return 0;
}