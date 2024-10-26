#include <stdio.h>

void dectobin(int num)
{
    int num1=num,x,y[100],i=0;
    do
    {
        x=num1%2;
        num1/=2;
        y[i]=x;
        i++;
        if (num1==0)
        break;
    } 
    while (num1>0);

    printf("The decimal number '%d' in binary is: ",num);
    for (int j=i-1;j>=0;j--)
    {
        printf("%d",y[j]);
    }
}

void bintodec(int num)
{
    
}

int main()
{
    int choice,numo;
    printf("What operation do you want to do?\n1. Decimal to Binary\n2. Binary to Decimal\nEnter the corresponding value:");
    scanf("%d",&choice);
    if (choice==1)
    {
        printf("Enter the Number (of base 10):");
        scanf("%d",&numo);
        dectobin(numo);
    }
}