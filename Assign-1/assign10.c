//Program to print Pascal's triangle

#include <stdio.h>

int main()
{
    int num,no=1;
    printf("How many rows of patterns are you looking for: ");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        for(int a=1;a<=num-i;a++)
        {
            printf("  ");
        }
        for(int j=0;j<=i;j++)
        {
            if (j==0||i==0)
            {
                no=1;
            }
            else
            {
                no=no*(i-j+1)/j;
            }
            printf("%4d",no);
        }
        printf("\n");
    }
    return 0;
}