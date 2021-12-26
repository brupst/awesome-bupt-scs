/*这里 n 大于等于 0，前几个 Catalan数为 C0=1,C1=1,C2=2,C3 = 5等。现请你写一段程序来计算Catalan数。
输入格式:
为一个整数 n (0<=n<=32)。
输出格式:
为第 n 项 catalan 数 （数字特别大，建议数据类型使用 long long）。*/

#include<stdio.h>

int isprime(int n);

int main()
{
    int n,x,y=0,count=0;
    int prime[10000]={0};
    scanf("%d",&n);
    for(x=2;x<n+1;x++)
    {
        if(isprime(x))
        {
            prime[y]=x;
            y++;
        }
    }
    for(y=0;prime[y]!=0;y++)
    {
        if(prime[y+1]==prime[y]+2)
            count++;
    }
    printf("%d",count);
}

int isprime(int n)
{
    int prime,x;
    if(n==2)
        return prime;
    for(x=2,prime=1;x*x<=n;x++)
    {
        if(n%x==0)
            prime=0;
        if(prime==0)
            break;
    }
        return prime;
}