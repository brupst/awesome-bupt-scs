/*已知正整数n与数列公式:
An = 1*2*3+2*3*4+3*4*5+…+(n-2)*(n-1)*n (n>=3)
An = 0 (n=1,2)
请根据n值计算该数列的前n项和的值,并输出。n的取值范围是(1<=n<=3000)。
注意：这里的An 只是一项，而我们要求的是计算该数列的前n项和。
提示：由于n值很大，建议使用long long型变量存储结果。
输入格式:
只有一个正整数n(1<=n<=3000)。
输出格式:
只有一个整数，为计算结果。*/

#include<stdio.h>
int main()
{
    long long n,x;
    long long unsigned result,sum,result2;
    sum=result=result2=0;
    n=x=0;
    scanf("%d",&n);
    if(n>=3)
    {
        for(x=1;x<=n-2;x++)
        {
            sum=x*(x+1)*(x+2);
            result+=sum;
            result2+=result;
        }
        printf("%lld\n",result2);
    }
    else
    {
        printf("0");
    }
    return 0;
}
