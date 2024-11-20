// To subtract without using (-)

#include <stdio.h>

#include<stdio.h>
int subtro(int subt1, int subt2)
{
    int num1;
    while (subt2 != 0)
    {
        num1 = (~subt1) & subt2;
        subt1 = subt1 ^ subt2;
        subt2 = num1 << 1;
    }
    return subt1;
}

int main()
{
    int no1,no2;
    printf("\nEnter the first number : ");
    scanf("%d",&no1);
    printf("\nEnter the second number : ");
    scanf("%d",&no2);
    printf("The subtraction of the numbers:\n%d minus %d without using minus (-) sign is %d.",no1,no2,subtro(no1,no2));
    return 0;
}
