/*已知一个整数n，打印1到n所有除以m后所得商正好是它的各个数字平方和的数。
输入格式:
为两个用空格分隔的整数，它们依次代表n、m（1<m,n<10000)。
输出格式:
按从小到大的顺序依次输出所有满足条件的整数，每个数占一行。测试用例保证有满足条件的数。*/

#include<stdio.h>

int power_number(int number);

int main()
{
    int number,n,t,m,x,y;
    scanf("%d%d",&n,&m);
    for(t=m;t<=n;t++)
    {
        x=t/m;
        number=power_number(t);
        if(number==x)
            printf("%d\n",t);
    }
    return 0;
}

int power_number(int number)
{
    int a,b;
    int result=0;
    while(1)
    {
        if(number>=10)
        {
            a=number%10;
            number/=10;
            result+=a*a;
        }
        else if(number<10)
        {
            result+=number*number;
            break;
        }
    }
    return result;
}
