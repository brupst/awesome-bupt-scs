/*请写出将一个整数逆序输出的函数。*/

#include <stdio.h>

void reverse(int n) ; 

int main()
{
    int     n;

    scanf("%d",&n);
    reverse(n) ;
    printf("\n");
    return 0;
}

void reverse(int n) 
{
    if(n/10==0)
    {
        printf("%d",n);
        return;
    }
    else
    {
        printf("%d",(n%10));
        reverse(n/10);
        return;
    }
}