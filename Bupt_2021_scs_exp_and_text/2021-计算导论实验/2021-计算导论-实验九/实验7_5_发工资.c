/*每到月底，公司就要给员工发工资。每个员工的工资都是由（100，50，20，10，5，2，1) 7种面值的钞票组成的。为了发工资的简便，
公司会尽量给员工发较大面值的钞票，例如某个员工的工资为1260，那么公司会给员工12张100元的、1张50元的、1张10的钞票。
你的任务是，告诉你某员工的工资，你来计算如何给员工发工资。
输入格式:
为一个正整数n（可以用int存储），代表某位员工的工资。
输出格式:
为给该员工发的钞票面值与数量。具体格式见样例。*/

#include<stdio.h>
int main()
{
    int salary[7]={0};
    int n;
    scanf("%d",&n);
    while(n>=100)
    {
        salary[0]++;
        n-=100;
    }
    while(n>=50)
    {
        salary[1]++;
        n-=50;
    }
    while(n>=20)
    {
        salary[2]++;
        n-=20;
    }
    while(n>=10)
    {
        salary[3]++;
        n-=10;
    }
    while(n>=5)
    {
        salary[4]++;
        n-=5;
    }
    while(n>=2)
    {
        salary[5]++;
        n-=2;
    }
    while(n>=1)
    {
        salary[6]++;
        n-=1;
    }
    if(salary[0]!=0)
        printf("100:%d\n",salary[0]);
    if(salary[1]!=0)
        printf("50:%d\n",salary[1]);
    if(salary[2]!=0)
        printf("20:%d\n",salary[2]);
    if(salary[3]!=0)
        printf("10:%d\n",salary[3]);
    if(salary[4]!=0)
        printf("5:%d\n",salary[4]);
    if(salary[5]!=0)
        printf("2:%d\n",salary[5]);
    if(salary[6]!=0)
        printf("1:%d\n",salary[6]);
    return 0;
}