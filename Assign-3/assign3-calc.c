#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double numos[],int size);
double subtro(double num1,double num2);
double multi(double numos[],int size);
double divi(double num1,double num2);
double loga(double num);
double root(double num);


int main()
{
    double num1,num2;
    int what;
    ques:
    printf("What do you want to do?\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Find the logarithmic value\n6. Find the square root\nEnter your choice:");
    scanf(" %d",&what);
    if (what==1)
    {
        double *axm=(double*)calloc(10,sizeof(double));
        printf("Enter the numbers you want to add (Put a '\\' after entering the numbers) :");
        for (int i=0;i<10;i++)
        {
            scanf("%lf",&axm[i]);
        }
        printf("The sum is: %.2lf.",add(axm,10));
    } 

    else if (what==2)
    {
        printf("Enter the first number:");
        scanf("%lf",&num1);
        printf("Enter the second number:");
        scanf("%lf",&num2);
        printf("The Subtraction of the numbers is: %.2lf",subtro(num1,num2));
    }

    else if (what==3)
    {
        double *axm=(double*)calloc(10,sizeof(double));
        for (int i=0;i<10;i++)
        {
            axm[i]=1.0;
        }
        printf("Enter the numbers you want to multiply (Put a '\\' after entering the numbers) :");
        for (int i=0;i<10;i++)
        {
            scanf("%lf",&axm[i]);
        }
        printf("The product is: %.2lf.",multi(axm,10));
    }

    else if(what==4)
    {
        printf("Enter the first number:");
        scanf("%lf",&num1);
        printf("Enter the second number:");
        scanf("%lf",&num2);
        printf("The Subtraction of the numbers is: %.2lf",divi(num1,num2));
    }

    else if (what==5)
    {
        printf("Enter the number whose log you want to find:");
        scanf("%lf",&num1);
        printf("The division of first number by the second number is:%.2lf",loga(num1));
    }
    
    else if(what==6)
    {
        printf("Enter the number whose square root you want to find:");
        scanf("%lf",&num1);
        printf("The division of first number by the second number is:%.2lf",root(num1));
    }

    else
    {
        printf("Enter a valid choice!");
    }
    return 0;

}

double add(double numos[],int size)
{
    double sum=0;
    for (int i=0;i<size;i++)
    {
        sum+=numos[i];
    }
    return sum;
}

double subtro(double num1,double num2)
{
    double sub;
    sub=num1-num2;
    return sub;
}

double multi(double numos[],int size)
{
    double multi=1;
    for(int i=0;i<size;i++)
    {
        multi*=numos[i];
    }
    return multi;
}

double divi(double num1,double num2)
{
    if (num2==0)
    {
        printf("Invalid.");
    }
    else
    {
        return num1/num2;
    }
}

double loga(double num)
{
    double logs;
    if (num>0)
    {
        logs=log(num);
    }
    return logs;
}

double root(double num)
{
    double roota;
    if (num>0)
    {
        roota=sqrt(num);
    }
    return roota;
}

