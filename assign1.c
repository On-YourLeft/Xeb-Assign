//Program to check if a number is armstrong or not

#include <stdio.h>
#include <math.h>

int order(int x)
{
    int n = 0;
    while (x) 
    {
        n++;
        x = x / 10;
    }
    printf("%d",x);
    return n;
}

int isArmstrong(int x)
{
    int n = order(x);
    int temp = x, sum = 0;
    while (temp) 
    {
        int r = temp % 10;
        sum += pow(r, n);
        temp = temp / 10;
    }

    if (sum == x)
        return 1;
    else
        return 0;
}

int main()
{
    int x;
    printf("Enter the number:");
    scanf("%d",&x);
    if (isArmstrong(x) == 1)
        printf("True\n");
    else
        printf("False\n");
    return 0;
}

