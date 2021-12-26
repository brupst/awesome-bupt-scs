/*现有函数f(n)，n为大于等于0的整数。当n等于0时f(n) = 0，当n大于0时 f(n)=f(n-1) +pow(n,3)*/

#include<stdio.h>

int    fuc(int n) ;

int main()
{
    int n ;

    scanf("%d",&n); 
    printf("%d\n",fuc(n));

    return 0 ;
}

int    fuc(int n) 
{
    int result;
    if(n==0)
    {
        return 0;
    }
    else
    {
        result=fuc(n-1)+n*n*n;
        return result;
    }
}