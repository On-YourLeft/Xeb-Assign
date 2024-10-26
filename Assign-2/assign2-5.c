//Program to find the sum of marks of an array

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
    printf("The sum of the marks of the students is %.1f.",sum);
    return 0;
}