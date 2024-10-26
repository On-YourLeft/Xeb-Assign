//Program to check in which quadrant the entered coordinates are

#include <stdio.h>

int quad(int x, int y)
{
    if ((x>0)&&(y>0))
    {
        printf("The coordinates x=%d & y=%d are in First Quadrant.\n",x,y);
    }
    else if ((x<0)&&(y>0))
    {
        printf("The coordinates x=%d & y=%d are in Second Quadrant.\n",x,y);
    }
    else if ((x<0)&&(y<0))
    {
        printf("The coordinates x=%d & y=%d are in Third Quadrant.\n",x,y);
    }
    else if ((x>0)&&(y<0))
    {
        printf("The coordinates x=%d & y=%d are in Fourth Quadrant.\n",x,y);
    }
    else if ((x==0)&&(y!=0))
    {
        printf("The coordinates x=%d & y=%d are on X-axis.\n",x,y);
    }
    else if ((y==0)&&(x!=0))
    {
        printf("The coordinates x=%d & y=%d are on Y-axis.\n",x,y);
    }
    else if ((x==0)&&(y==0))
    {
        printf("The coordinates are on the Origin.\n");
    }
    return 0;
}

int main()
{
    int x,y;
    printf("Enter the X-coordinate:");
    scanf("%d",&x);
    printf("Enter the Y-coordinate:");
    scanf("%d",&y);
    quad (x,y);
    return 0;
}