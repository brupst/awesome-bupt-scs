/*设计函数int mypow(int x,int n)，返回正整数x的n次幂，如mypow(2,10)值为1024。
输入与输出要求： 输入两个非负整数x、和n，x的n次幂不会超过int型范围。输出计算结果，占一行。
函数接口定义：
函数原型如下：
int mypow(int x,int n);
其中 x 和 n 都是用户传入的参数。 x 、n 以及x 的n次幂都不超过int的范围。函数须返回 x 的 n 次幂*/

#include<stdio.h>

int mypow(int , int ) ;

int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    printf("%d\n",mypow(x,n));
    return 0;
}

int mypow(int x, int n)
{
    long long y;
    unsigned long long result=1;
    if(n==0)
    {
        result=1;
    }
    else
    {
        for(y=1;y<=n;y++)
        {
            result*=x;
        }
    }
    return result;
}