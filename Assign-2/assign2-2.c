//Program to print grade of students as per their marks

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number of students:");
    scanf("%d",&num);
    float (marks[num]);
    for (int i=0;i<num;i++)
    {
        printf("Enter the marks of student %d:",i+1);
        scanf("%f",&marks[i]);
    }
    for (int i=0;i<num;i++)
    {
        if (marks[i]>=75.0 && marks[i]<=100.0)
        {
            printf("The student %d with marks %.1f has an A grade.\n",i+1,marks[i]);
        }
        else if (marks[i]>=60.0 && marks[i]<75.0)
        {
            printf("The student %d with marks %.1f has a B grade.\n",i+1,marks[i]);
        }
        else if (marks[i]>=40.0 && marks[i]<60.0)
        {
            printf("The student %d with marks %.1f has a C grade.\n",i+1,marks[i]);
        }
        else if (marks[i]>=0.0 && marks[i]<40.0)
        {
            printf("The student %d with marks %.1f has a D grade.\n",i+1,marks[i]);
        }
        else
        {
            printf("Are your marks even valid student %d?\n",i+1);
        }
    }
    return 0;
}