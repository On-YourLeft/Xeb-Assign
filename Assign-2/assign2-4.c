//Program to find who and how many students scored 99 marks

#include <stdio.h>

int main()
{
    int num,x=0;
    printf("Enter the number of students:");
    scanf("%d",&num);
    float marks[num];
    for (int i=0;i<num;i++)
    {
        printf("Entered the marks of student %d:",i+1);
        scanf("%f",&marks[i]);
    }
    printf("\n");
    for (int i=0;i<num;i++)
    {
        if (marks[i]==99.0)
        {
            x+=1;
            printf("Student %d scored 99 marks.\n",i+1);
        }
    }
    printf("The number of students with 99 marks are %d.",x);
    return 0;
}
