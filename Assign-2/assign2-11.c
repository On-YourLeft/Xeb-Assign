//Program to insert an element in front, between and end of an array

#include <stdio.h>

int main()
{
    int num,what,front,betw,betwind,end;
    printf ("How many items do you want your array to have:");
    scanf(" %d",&num);
    int arra[num+1];
    for (int i=0;i<num;i++)
    {
        printf("Enter the element %d:",i+1);
        scanf(" %d",&arra[i]);
    }
    printf("Where do you want to insert the item:\n1. Front\n2. In between\n3. End\nEnter the corresponding number:\t");
    scanf(" %d",&what);
    printf("The array before any insertion:\t");
    for(int i=0;i<num;i++)
    {
        printf("%d\t",arra[i]);
    }
    if (what==1)
    {
        for(int i=num;i>=0;i--)
        {
            arra[i+1]=arra[i];
        }

        printf("\nEnter the item to be inserted in the front of the array:");
        scanf(" %d",&front);
        arra[0]=front;
        printf("\nThe array after insertion at the front :\t");
        for(int i=0;i<=num;i++)
        {
            printf("%d\t",arra[i]);
        }
    }
    else if (what==2)
    {
        printf("\nEnter the item to be inserted at a specified position in the array: ");
        scanf(" %d",&betw);
        printf("Enter the specified position: ");
        scanf(" %d",&betwind);
        for(int i=num;i>=(betwind-1);i--)
        {
            arra[i+1]=arra[i];
        }
        arra[betwind-1]=betw;
        printf("The array after insertion at the specified position '%d' :\t",betwind);
        for (int i=0;i<=num;i++)
        {
            printf("%d\t",arra[i]);
        }
    }
    else if(what==3)
    {
        printf("\nEnter the item to be inserted at the end:");
        scanf(" %d",&end);
        arra[num]=end;
        printf("The array after insertion at the end :\t");
        for (int i=0;i<=num;i++)
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