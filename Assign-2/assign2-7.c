//Program to check if the score is even or odd

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number of students:");
    scanf("%d",&num);
    int marks[num],sum=0;
    for (int i=0;i<num;i++)
    {
        printf("Entered the marks of student %d:",i+1);
        scanf("%d",&marks[i]);
    }
    printf("\n");
    for (int i=0;i<num;i++)
    {
        if ((marks[i]%2)==0)
        {
            printf("The score of student %d is %d and it is even.\n",i+1,marks[i]);
        }
        else 
        {
            printf("The score of student %d is %d and it is odd.\n",i+1,marks[i]);
        }
    }
    return 0;
}