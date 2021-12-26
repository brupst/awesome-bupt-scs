/*编写一个程序，用下面的公式计算pow(e,x)的值。pow(e,x)=Σpow(x,0)/n!,n趋于+∞；
输入格式:
只有一个浮点数x，即代表pow(e,x)中的指数x,且x满足x<=20。
输出格式:
只有一个浮点数，即pow(e,x)的值，保留4位有效数字。*/

#include<stdio.h>

double factorial(double N);

int main()
{
    double x,y,n;
    double result=0;
    scanf("%lf",&x);
    for(n=0;;n++)
    {
        y=(pow(x,n)/factorial(n));
        result+=y;
        if(y>=0&&y<=10e-8||0>=y&&y>=-10e-8)
        {
            break;
        }
    }
    printf("%.4f",result);
    return 0;
}

double factorial(double N)
{
    double n;
    double result=1;
    for(n=0;n<=N;n++)
    {
        if(n==0)
        {
            result=1;
        }
        else
        {
        result*=n;
        }
    }
    return result;
}