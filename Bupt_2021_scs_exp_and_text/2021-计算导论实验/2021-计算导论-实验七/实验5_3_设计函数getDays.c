/*设计函数int getDays(int year,int month)，根据给定的年year和月份month,计算该月的天数并返回。 提示：注意闰年的判断。
输入与输出要求： 输入两个整数y,m，即年份与月份。输出该年内该月的天数，占一行。 测试用例保证输入合法。
函数接口定义：
函数原型如下：
int getDays(int year,int month);
其中 year 和 month 都是用户传入的参数，分别代表年份和月份。函数须返回该月的天数。*/

#include<stdio.h>

int getDays(int,int);

int main()
{
    int year,month;
    scanf("%d%d",&year,&month);
    printf("There are %d days in month %d year %d.",getDays(year,month), month, year) ;
    return 0 ;    
}

int getDays(int year,int month)
{
    int judge=0;
    int days;
    if((year%4==0&&year%100!=0)||(year%400==0))
    {
        judge=1;
    }
    if(judge==1&&month==2)
    {
        days=29;
    }
    else if(judge==0&&month==2)
    {
        days=28;
    }
    else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        days=31;
    }
    else
    {
        days=30;
    }
    return days;
}