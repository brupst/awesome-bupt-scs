/*如果一个整数的各因子（包括1但不包括该整数本身)值之和等于该整数，则该整数称为“完全数”（perfect number)。
例如，6是一个完全数，因为6=1+2+3。你的任务是设计函数isPerfect和printPerfect，判断并打印出区间[a,b]（1<=a<b<=20000）内的所有完全数，并统计完全数的总个数。
isPerfect函数原型：int isPerfect(int n);
用于判断正整数n是否为完全数，若是，则返回值为1，否则为0。
printPerfect函数原型：void printPerfect(int n);
用于打印出一个完全数n的所有因子，当执行printPerfect(6)时，打印效果为：6=1+2+3。
输入与输出要求： 输入两个正整数a和b，输出区间[a,b]内的所有完全数及完全数的总个数。
函数接口定义：
void printPerfect(int n);
其中 n 是用户传入的参数。 函数没有返回值。
int isPerfect(int n);
其中 n 是用户传入的参数。如果 n是完全数，则函数须返回 1，否则返回0 。*/

#include <stdio.h>

//判断一个数是否为完全数的函数
int isPerfect(int);

//打印完全数的函数 
void printPerfect(int);

int main()
{
    int i,a,b,count;

    scanf("%d%d",&a,&b);
    count = 0 ;//a,b两数间完全数的数量，初始化为0 
    for(i=a;i<=b;i++)
    {
        if (isPerfect(i))  //如果是完全数 
        {
            printPerfect(i) ;//打印该完全数 
            count ++ ;  //计数器加1 
        }        
    }
    printf("The total number is %d.\n",count);//输出a,b两数间完全数的数量 
    return 0 ;
}

int isPerfect(int i)
{
    int x,z;
    int sum=0;
    for(x=1;x<=i/2;x++)
    {
        if(i%x==0)
        {
            sum+=x;
        }
    }
    if(i==sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printPerfect(int i)
{
    int x,z;
    int sum=0;
    printf("%d=1",i);
    for(x=2;x<=i/2;x++)
    {
        if(i%x==0)
        {
            printf("+%d",x);
        }
    }
    printf("\n");
    return;
}