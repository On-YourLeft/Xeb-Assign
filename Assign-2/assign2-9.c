//Program to find a peak element which is not smaller than it's neighbours

#include <stdio.h>

int main()
{
    int peak=0,elements[10],x=0;
    for (int i=0;i<10;i++)
    {
        printf("Enter the elemednkndknt %d:",i+1);
        scanf("%d",&elements[i]);
    }
    for(int i=0;i<10;i++)
    {
        check:
        if (elements[i]>peak)
        {
            peak=elements[i];
            x=i;
            if (elements[i+1]>peak)
            {
                goto check;
            }
            break;
        }
    }
    printf("The first peak element which is not smaller than it's neighbours is element %d which is %d.",x+1,peak);
    return 0;
}