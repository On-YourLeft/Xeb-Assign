// To subtract without using (-)

#include <stdio.h>

int main()
{
    int a, b,c;
    a = 0b101;
    b = ~a;
    c = ~5;
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
}