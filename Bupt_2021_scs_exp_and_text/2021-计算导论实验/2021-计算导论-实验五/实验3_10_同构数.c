/*所谓“同构数”是指这样的数，它出现在它的平方数的右边，例如5的平方数是25, 25的平方数是625，所以5和25都是同构数。你的任务是判断整数x是否是同构数。
若是同构数，输出“Yes”，否则输出“No”。x的取值范围是(1<=x<=10000),如果输入的x不在允许范围内，则输出错误提示信息“x out of range”。
输入格式:
只有一个整数。测试用例保证所有输入可以用int存储。
输出格式:
只有一行，为判断结果。*/

#include<stdio.h>
#include<math.h>
int judgement(int N);

int main()
{
    int N,judge;
    scanf("%d",&N);
    if((N<1)||(N>10000))
        printf("%d out of range",N);
    else
    {
        judge=judgement(N);
        if(judge==1)
            printf("Yes");
        else
            printf("No");
    }
    return 0;
}

int judgement(int N)
{
    long power,n,q,m;
    long x=0;
    power=pow(N,2);
    m=N;
    while(m>10)
    {
        m/=10;
        x++;
    }
    n=pow(10,x+1);
    q=power%n;
    if(q==N)
        return 1;
    else
        return 0;
}