/*已知一个正整数n，n的范围是1—999999999。你的任务是把这个整数分解为单个数字，然后从左至右依次打印出每一个数字。例如将整数“12345”分解，得到“1 2 3 4 5”。
输入格式:
只有一个正整数。测试用例保证合法。
输出格式:
只有一行，为输入整数的拆分结果，相邻两个数字之间有一个空格，最后一个数字后是换行符。例如12345的拆分结果为：1 2 3 4 5。*/

#include<stdio.h>
void FA(long n);
int main()
{
    long n;
    scanf("%ld",&n);
    FA(n);
    return 0;
}

void FA(long n)
{
    if(n<10)
        printf("%d",n);
    else
    {
        FA(n/10);
        printf(" %d",n%10);
    }
}
