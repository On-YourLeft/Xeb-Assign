//Program to cyclically rotate an array

#include <stdio.h>

int main()
{
    int num,temp;
    printf("How many elements in the array?\nEnter the number:");
    scanf("%d",&num);
    int arra[num];
    for (int i=0;i<num;i++)
    {
        printf("Enter the element %d:",i+1);
        scanf("%d",&arra[i]);
    }
    printf("Array before the rotation:\t");
    for (int i=0;i<num;i++)
    {
        printf("%d\t",arra[i]);
    }
    temp=arra[num-1];
    for(int i=num;i>=0;i--)
    {
        arra[i+1]=arra[i];
    }
    arra[0]=temp;
    printf("\nArray after the rotation:\t");
    for (int i=0;i<num;i++)
    {
        printf("%d\t",arra[i]);
    }
    return 0;
}