//Program to increase every student marks by 5 and print updated array

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number of students whose marks are to be inputted:");
    scanf("%d",&num);
    float stud[num];
    for(int i=0;i<num;i++)
    {
        printf("Enter the marks of the student %d:",i+1);
        scanf("%f",&stud[i]);
    }
    printf("\n\nMarks of the students are -\n");
    for (int i=0;i<num;i++)
    {
        printf("The marks of the student %d is %.2f.\n",i+1,stud[i]);
    }
    printf("\n\nThe updated marks after increasing them by 5 are-\n");
    for (int i=0;i<num;i++)
    {
        stud[i]+=5;
        printf("The marks of the student %d is %.2f.\n",i+1,stud[i]);
    }
    return 0;
}