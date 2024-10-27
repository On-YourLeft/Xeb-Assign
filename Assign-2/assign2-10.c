//Program to count prime numbers in an array

#include <stdio.h>

int main()
{
    int num,prime=0;
    printf("How many numbers do you want to enter?\n");
    scanf("%d",&num);
    int numbers[num];
    for (int i=0;i<num;i++)
    {
        printf("Enter the number %d:",i+1);
        scanf("%d",&numbers[i]);
    }
    for (int i=0;i<num;i++)
    {
        int x=0;
        for (int j=1;j<=numbers[i];j++)
        {
            if (numbers[i]%j==0)
            {
                x++;
            }
        }
        if (x<=2)
        {
            prime++;
        }
    }
    printf("The number of prime numbers in the array is %d.",prime);
    return 0;
}