//Program to print duplicates in a given array

#include <stdio.h>

int main()
{
    int num;
    printf("How many elements in the array?\nEnter the number:");
    scanf("%d",&num);
    int arra[num];
    for (int i=0;i<num;i++)
    {
        printf("Enter the element %d:",i+1);
        scanf("%d",&arra[i]);
    }
    printf("The duplicate elements are: ");
    for (int i=0;i<num;i++)
    {
        for (int j=(i+1);j<=num;j++)
        {
            if (arra[i]==arra[j])
            {
                printf("%d\t",arra[i]);
            }
        }
    }
    return 0;
}