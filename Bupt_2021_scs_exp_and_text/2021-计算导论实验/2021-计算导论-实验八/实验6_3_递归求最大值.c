/*写一个函数可以读入n（0<n<100）个整数，并求出这n个整数中的最大值。*/

#include <stdio.h>

int findMax(int n) ;

int main()
{   
    int n ; 

    scanf("%d", &n); 
    printf("%d\n" , findMax( n ) ) ; 

    return 0;
}

int findMax(int n) 
{
    int number,max;
    scanf("%d",&number);
    if(n==1)
    {
        return number;
    }
    else
    {
        max=findMax(n-1);
        if(number>=max)
        {
            return number;
        }
        else
        {
            return max;
        }
    }
}