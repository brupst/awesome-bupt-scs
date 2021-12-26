/*给定一个长度为n的整数数组，数组中连续的相等元素构成的子序列称为平台。试设计算法，求出数组中最长平台的长度。
输入格式:
共2行，第一行为一个整数n(0<n<=1000)，代表输入整数个数，第二行为n个用空格分隔的整数。测试用例保证所有整数可以用int存储。
输出格式:
只有一行，为一个整数，代表输入数组的最长平台长度。*/

#include<stdio.h>
int main()
{
    int n,x,y=0;
    int max=0;
    scanf("%d",&n);
    int number[n];
    for(x=0;x<n;x++)
        scanf("%d",&number[x]);
    for(x=0;x<n;x++)
    {
        if(number[x]==number[x+1])
        {
            y++;
            if(y>=max)
                max=y;
        }
        else
            y=0;
    }
    printf("%d",max+1);
    return 0;
}