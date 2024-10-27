//Program to find average scores of students in an array

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number of students:");
    scanf("%d",&num);
    float marks[num],sum=0.0;
    for (int i=0;i<num;i++)
    {
        printf("Entered the marks of student %d:",i+1);
        scanf("%f",&marks[i]);
    }
    printf("\n");
    for (int i=0;i<num;i++)
    {
        sum+=marks[i];
    }
    printf("The average of the marks of the students is %.2f.",sum/num);
    return 0;
}