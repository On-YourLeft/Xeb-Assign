/*Program to print
1
01
101
0101
10101
pattern*/

#include <stdio.h>

int main()
{
    int num;
    printf("How many rows of patterns are you looking for: ");
    scanf("%d",&num);
    for (int i = 1; i<=num; i++)
    {
        for (int j = 1; j<=i; j++)
        {
            if(i%2!=0)
            {
                if(j%2!=0)
                {
                    printf("1 ");
                }
                else
                {
                    printf("0 ");
                }
            }
            else
            {
                if(j%2==0)
                {
                    printf("1 ");
                }
                else
                {
                    printf("0 ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}