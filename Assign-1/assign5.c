//Program to check if a number is perfect or not (sum of factors = number)

#include <stdio.h>

int perfect(int num)
{
    int x=0;
    for (int i=1;i<num;i++)
    {
        if ((num%i)==0)
        {
            x+=i;
        }
    }
    if (x==num)
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
    int number;
    printf("Enter the number to be checked for a perfect number:");
    scanf("%d",&number);
    if (perfect(number)==1)
    {
        printf("The number %d is a perfect number.\n",number);
    }
    else
    {
        printf("The number %d is not a perfect number.\n",number);
    }
    return 0;
}