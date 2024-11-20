//Program to swap two numbers in 4 different ways

#include <stdio.h>

void swap1(int num1,int num2)
{
    int x;
    x=num1;
    num1=num2;
    num2=x;
    printf("The swapped numbers using third variable are:%d & %d.\n",num1,num2);
}

void swap2(int num1, int num2)
{
    num1=num1-num2;
    num2=num1+num2;
    num1=num2-num1;
    printf("The swapped numbers without using third variable are:%d & %d.\n",num1,num2);
}

void swap3(int num1,int num2)
{
    num1=num1^num2;
    num2=num1^num2;
    num1=num1^num2;
    printf("The swapped numbers using bitwise XOR are:%d & %d.\n",num1,num2);
}

void swap4(int *num1, int *num2)
{
    int num;
    num=*num1;
    *num1=*num2;
    *num2=num;
    printf("The swapped numbers using pointers are:%d & %d.\n",*num1,*num2);
}

int main()
{
    int number1,number2,way;
    printf("Enter the first number:");
    scanf("%d",&number1);
    printf("Enter the second number:");
    scanf("%d",&number2);
    printf("The numbers before swapping are %d and %d.\n",number1,number2);
    dodo:
    printf("In what way do you want to swap\n1. By using third Variable\n2. Without using third Variable\n3. Using bitwise XOR\n4. Using pointers\nEnter the corresponding number:");
    scanf(" %d",&way);
   switch (way)
   {
       case (1):
       swap1(number1,number2);
       break;

       case(2):
       swap2(number1,number2);
       break;

       case(3):
       swap3(number1,number2);
       break;

       case(4):
       swap4(&number1,&number2);
       break;

       default:
       printf("\nInvalid. Choose again.\n");
       goto dodo;
       break;
   }

   return 0;

}