/*请写程序计算并输出向量的内积。
输入格式:
共两行，第一行一个整数n，1<=n<=10，第二行2Xn个整数（以空格分隔），即两个长度为n的一维数组（向量）。
输出格式:
只有一个整数，为计算结果。测试用例保证所有整数（包括计算过程中的）可以用int存储。*/

#include<stdio.h>
int main()
{
    int n,x,y,result=0;
    scanf("%d",&n);
    int number[2*n];
    for(x=0;x<2*n;x++)
        scanf("%d",&number[x]);
    for(x=0;x<=n-1;x++)
        result+=number[x]*number[x+n];
    printf("%d",result);
    return 0;
}