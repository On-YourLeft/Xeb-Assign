//Program to check if a number is armstrong or not

#include <stdio.h>
#include <math.h>

int order(int a)
{
    int x = 0;
    while (a>0) 
    {
        x++;
        a /= 10;
    }
    return x;
}

int power(int numbo, int exp) 
{
    int prod = 1;
    for (int i = 0; i < exp; i++) 
    {
        prod *= numbo;
    }
    return prod;
}

int isArms(int numo)
{
    int powo = order(numo);
    int num1 = numo, sum = 0;
    while (num1>0) 
    {
        int rem = num1 % 10;
        sum +=power(rem,powo);
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

int main()
{
    int x;
    printf("Enter the number:");
    scanf("%d",&x);
    if (isArms(x) == 1)
        printf("The Number is an Armstrong's number.\n");
    else
        printf("The number is not an Armstrong's number.\n");
    return 0;
}