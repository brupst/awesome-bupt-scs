/*设计递归函数void void printFactor( int, int );打印出对n进行素数分解的结果。
当执行void printFactor(60,1)时，打印效果为：
60=2*2*3*5。
关于素数分解的描述，见讲义。
设计程序，已知一段数据范围[a,b]，且a<=b，要求对其中的每一个数进行素数分解。你也可以设计其它辅助函数，如判断素数的函数isPrime(n)。
输入与输出要求： 输入两个正整数a、b，代表所分解的区间，满足1<=a<=b<=100000，且b-a<=100。输出b-a+1行，即b-a+1个数的分解。*/

#include<stdio.h>

void printFactor( int, int ); 

int main()
{
    int a,b,i ;

    scanf( "%d%d", &a, &b );
    for( i = a ; i <= b ; i++ )
        printFactor( i , 1 ) ;    

    return 0;
}

int Isprime(int n)
{
    int prime,i;
    for(i=2,prime=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            prime=0;
            break;
        }
    }
    if(prime)
        return 1;
    else
        return 0;
}

void printFactor( int n, int a)
{
    int x,y;
    if(a==1&&n!=1)
        printf("%d=",n);
	if(a==1&&n==1)
        printf("1=1\n");
    if(Isprime(n)&&a==1)
    {
        printf("%d\n",n);
        return;
    }
    else if(Isprime(n)&&a==0)
    {
        printf("*%d\n",n);
        return;
    }
    else
    {
        for(x=2;x<n/2;x++)
        {
            if(Isprime(x)&&n%x==0)
            {
                if(a==1)
                {
                    printf("%d",x);
                    a=0;
                    break;
                }
                else
                {
                   printf("*%d",x); 
                   break;
                }
            }
        }
        printFactor(n/x,a);
    }
}
