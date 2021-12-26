/*任意给定n个整数，求这n个整数序列的和、最小值和最大值。
输入格式:
第一行为一个整数n（0<n<100)，代表要输入的整数个数；第二行为用空格分隔的n个整数。测试用例保证所有整数及求和结果等均可以用int存储。
输出格式:
只有一行，为三个空格分隔的，依次代表整数序列的和、最大值和最小值.*/

#include<stdio.h>
int main()
{
    int N,max,n,number,min;
    int sum=0;
    max=0;
    min=1000000;
    scanf("%d",&N);
    for(n=1;n<=N;n++)
    {
        scanf("%d",&number);
        sum+=number;
        if(max<=number)
        {
            max=number;
        }
        if(min>=number)
        {
            min=number;
        }
    }
    printf("%d %d %d",sum,max,min);
    return 0;
}