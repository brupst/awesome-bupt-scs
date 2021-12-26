/*现有若干行正整数，请你写一段程序分别统计每一行中有多少个质数。
输入格式:
第一行为一个整数n(0<n<10)，代表测试用例行数。后边是n行，每行为若干个用空格分隔的正整数。这些正整数的最后是-1，表示此行结束。
输出格式:
为n行，每行一个整数，对应于输入的每一行中质数的个数。
测试用例保证输入合法，且所有整数可以用int存储*/

#include<stdio.h>
#include<math.h>

int IsPrime(int number);

int main()
{
    int number,N,n;
    int judge=0;
    int prime=0;
    scanf("%d",&N);
    for(n=1;n<=N;n++)
    {
        prime=0;
        while((scanf("%d",&number)==1)&&(number!=-1))
        {
            judge=IsPrime(number);
            if(judge)
                prime++;
        }
        printf("%d\n",prime);
    }
    return 0;
}

int IsPrime(int number)
{
    int Prime,n;
    for(n=2,Prime=1;n<=sqrt(number);n++)
    {
        if(number%n==0)
            Prime=0;
    }
    if(Prime==0)
        return 0;
    else if(Prime==1)
        return 1;
}
