/*已知一个长度为n的整数数组，在保证原顺序的前提下，将该数组中所有的偶数放到所有的奇数之前，存到一个新数组中，并将新数组输出。
输入格式:
共2行，第一行为一个整数n(0<n<=200)，代表输入整数个数，第二行为n个用空格分隔的整数，需保存在待处理数组中。测试用例保证所有整数可以用int存储。
输出格式:
只有一行，为新数组中的元素，数与数之间用一个空格分隔，第n个数后是换行符。*/

#include<stdio.h>
int main()
{
    int n,x,y=0;
    scanf("%d",&n);
    int number[n];
    int another[n];
    for(x=0;x<n;x++)
        scanf("%d",&number[x]);
    for(x=0;x<n;x++)
    {
        if(number[x]%2==0)
        {
            another[y]=number[x];
            y++;
        }
    }
    for(x=0;x<n;x++)
    {
        if(number[x]%2==1)
        {
            another[y]=number[x];
            y++;
        }
    }
    for(x=0;x<n;x++)
    {
        if(x<n-1)
            printf("%d ",another[x]);
        else
            printf("%d\n",another[x]);
    }
    return 0;
}