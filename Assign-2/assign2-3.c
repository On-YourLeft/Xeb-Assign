//Program to find out who scored first 99 marks in an array

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number of students:");
    scanf("%d",&num);
    float (marks[num]);
    for (int i=0;i<num;i++)
    {
        printf("Enter marks of the student %d:",i+1);
        scanf("%f",&marks[i]);
    }
    printf("\n");
    for (int i=0;i<num;i++)
    {
        if (marks[i]==99.0)
        {
            printf("Student %d scored the first 99 marks.",i+1);
            break;
        }
    }
    return 0;
}