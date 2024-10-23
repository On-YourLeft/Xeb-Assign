//Program to check if a number is armstrong or not

#include <stdio.h>
#include <math.h>

int order(int a)
{
    int x = 0;
    while (a) 
    {
        x++;
        a /= 10;
    }
    return x;
}

int isArmstrong(int numo)
{
    int power = order(numo);
    int num1 = numo, sum = 0;
    while (num1) 
    {
        int rem = num1 % 10;
        sum += pow(rem, power);
        num1 /= 10;
    }

    if (sum == numo)
    {
        return 1;
    }
    else
    {        
        return 0;
    }
}

/*int order(int x)
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
}*/

int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d",&num);
    if (isArmstrong(num) == 1)
        printf("The Number is an Armstrong's number.\n");
    else
        printf("The number is not an Armstrong's number.\n");
    int x;
    printf("Enter the number:");
    scanf("%d",&x);
    if (isArmstrong(x) == 1)
        printf("True\n");
    else
        printf("False\n");
    return 0;
}