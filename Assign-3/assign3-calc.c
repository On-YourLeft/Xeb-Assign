#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double numos[],int size)
{
    double sum=0;
    for (int i=0;i<size;i++)
    {
        sum+=numos[i];
    }
    printf("\n%lf\n",sum);
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
    for(int i=1;i<=size;i++)
    {
        multi*=numos[i];
    }
    return multi;
}

/*double div(double num1,double num2)
{
    double divo;
    divo=num1/num2;
    return divo;
}*/

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

int main()
{
    double num1,num2;
    int what;
    ques:
    printf("What do you want to do?\n1. Add them\n2. Subtract them\n3. Multiply them\n4. Divide them\n5. Find the logarithmic value\n6. Find the square root\nEnter your choice:");
    scanf(" %d",&what);
    if (what==1)
    {
        double *axm=(double*)calloc(10,sizeof(double));
        printf("Enter the numbers you want to add:");
        for (int i=0;i<10;i++)
        {
            scanf("%lf",&axm[i]);
        }
        printf("The sum is: %.2lf.",add(axm,10));
    } 

}
