/*有一堆桃子不知数目，猴子第一天吃掉一半，觉得不过瘾，又多吃了一个，第二天照此办理，吃掉剩下桃子的一半另加一个，天天如此，到第n天早上，
猴子发现只剩一个桃子了，问这堆桃子原来有多少个？
输入格式:
只有一个整数n(0<n<30)，代表题目中的n。测试用例保证输入合法。
输出格式:
只有个整数，代表这堆桃子的个数。*/

#include<stdio.h>

int FA(int n);

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",FA(n));
    return 0;
}

int FA(int n)
{
    if(n==1)
        return 1;
    else
        return 2*FA(n-1)+2;
}