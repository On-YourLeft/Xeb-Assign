/*Program to print 
0        0
01      01
010    010
0101  0101
0101001010
*/

#include <stdio.h>

int main()
{
    int num;
    printf("How many rows of patterns are you looking for: ");
    scanf("%d",&num);
    
    
    for(int i = 0; i<=num; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            if(j%2==0)
            {
                printf("0 ");
            }
            else
            {
                printf("1 ");
            }
        }
        for(int j = 2*(num-i)-1; j>=0; j--)
        {
            printf("  ");
        }
        for(int j = 0; j<=i; j++)
        {
            if(j%2==0)
            {
                printf("0 ");
            }
            else
            {
                printf("1 ");
            }
        }
        printf("\n");
    }
    return 0;
}