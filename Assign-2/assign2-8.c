//Program to find minimum and maximum scores of an array

#include <stdio.h>

int main()
{
    int num,min=0,max=0,x=0,y=0;
    printf("Enter the number of students:");
    scanf("%d",&num);
    int marks[num],sum=0;
    for (int i=0;i<num;i++)
    {
        printf("Entered the marks of student %d:",i+1);
        scanf("%d",&marks[i]);
    }
    printf("\n");
    min=marks[1];
    for (int i=0;i<num;i++)
    {
        if (marks[i]<min)
        {
            min=marks[i];
            x=i;
        }
        else if (marks[i]>max)
        {
            max=marks[i];
            y=i;
        }
    }
    printf("The minimum marks scored are %d by student %d.\n",min,x+1);
    printf("The maximum marks scored are %d by student %d.\n",max,y+1);

    return 0;
}