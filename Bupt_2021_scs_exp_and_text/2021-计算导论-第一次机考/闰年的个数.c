/*现有若干行年份，请你写一段程序分别统计每一行中有多少个闰年。
输入格式:
第一行为一个整数n(0<n<=10)，代表测试用例行数。后边是n行，每行为若干个用空格分隔的正整数（代表需要统计的年份，这些年份值在1到3000之间）。
这些正整数的最后是-1，表示此行结束。
输出格式:
为n行，每行一个整数，对应于输入的每一行中闰年的个数。*/

#include<stdio.h>

int judge(int year);

int main()
{
    int x,year,n,y=0;
    scanf("%d",&n);
    for(x=0;x<n;x++)
    {
        while(1)
        {
            scanf("%d",&year);
            if(year==-1)
                break;
            else
            {
                if(judge(year))
                    y++;
            }
        }
        printf("%d\n",y);
        y=0;
    }
    return 0;
}

int judge(int year)
{
    if((year%4==0&&year%100!=0)||(year%400)==0)
        return 1;
    else
        return 0;
}