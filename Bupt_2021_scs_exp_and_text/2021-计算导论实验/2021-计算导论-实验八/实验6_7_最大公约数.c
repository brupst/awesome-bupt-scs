/*设计递归函数int GCD(int a,int b);计算正整数a和b的最大公约数并返回。如GCD(32,48)为16。
GCD(a,b)递归定义为：
GCD(a,b)=GCD(b,a MOD b) 当 a MOD b≠0
GCD(a,b)=b 当 a MOD b=0
输入与输出要求： 输入两个正整数a和b，输出两数的最大公约数，占一行。*/

#include<stdio.h>

int GCD(int a , int b );

int main()
{
    int        a , b ;

    scanf("%d%d", &a , &b );
    printf( "%d\n" , GCD( a, b ) ) ;

    return 0 ;    
}

int GCD(int a , int b )
{
    int temp;
    if(a<=b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    if(a%b==0)
    {
        return (b);
    }
    else
    {
        return GCD(b,a%b);
    }
}