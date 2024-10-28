//Program to delete an item from the front, between, or end of an array

#include <stdio.h>

int main()
{
    int num,what,betw;
    printf("How many elements do you want in the array?\nEnter the number:");
    scanf(" %d",&num);
    int arra[num+1];
    for (int i=0;i<num;i++)
    {
        printf("Enter the element %d:",i+1);
        scanf(" %d",&arra[i]);
    }
    printf("From where do you want to delete the element?\n1. Front\n2. In between\n3. The end\nEnter the corresponding number:");
    scanf("%d",&what);
    printf("The array before deletion:\t");
    for (int i=0;i<num;i++)
    {
        printf("%d\t",arra[i]);
    }
    if (what==1)
    {
        for(int i=1;i<num;i++)
        {
            arra[i-1]=arra[i];
        }
        printf("\nThe array after deletion from the front :\t");
        for(int i=0;i<num-1;i++)
        {
            printf("%d\t",arra[i]);
        }
    }
    else if (what==2)
    {
        printf("\nElement at what position do you want to delete?\nEnter the number:");
        scanf("%d",&betw);
        for (int i=betw;i<num;i++)
        {
            arra[i-1]=arra[i];
        }
        printf("The array after deletion from the position %d is:\t",betw);
        for (int i=0;i<num-1;i++)
        {
            printf("%d\t",arra[i]);
        }
    }
    else if (what==3)
    {
        arra[num-1]=0;
        printf("\nThe array after deletion from the end is:\t");
        for (int i=0;i<num-1;i++)
        {
            printf("%d\t",arra[i]);
        }
    }
    else
    {
        printf("Invalid input.");
    }
    return 0;
}