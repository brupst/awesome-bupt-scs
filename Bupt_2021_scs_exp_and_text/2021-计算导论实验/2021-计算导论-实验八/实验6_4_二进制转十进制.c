/*设计递归函数int convert(int n);用于将二进制数n转换为十进制数并返回。*/

#include<stdio.h>

int convert(int n);

int main()
{
    int        n ;

    scanf("%d",&n);

    printf("%d\n",convert(n)) ;
    return 0 ;    
}

int convert(int n)
{
    int result;

    if(n<=1)
    {
        return n;
    }
    else
    {
        result=n%10+convert(n/10)*2;
        return result;
    }
}