/*请写一段正负数统计的程序。
输入格式:
为若干整数，以-1结束（测试数据保证这组数中只有最后一个-1）。
输出格式:
共两行，第一行为三个整数（用一个空格分隔），依次为这组数中正数的个数，0的个数和负数的个数（不统计最后的-1）。
第二行为用一个空格分隔的两个整数，依次为这组数中所有正数的和及所有负数的和（不包括最后的-1）。
测试数据保证求和的结果可以用int型存储。*/

#include<stdio.h>
#define STOP -1
int main()
{
    int positive=0;
    int negative=0;
    int zero=0;
    int number;
    int positive_sum=0;
    int negative_sum=0;
    while((scanf("%d",&number)==1)&&(number!=STOP))
    {
        if(number>0)
        {
            positive++;
            positive_sum+=number;
        }
        else if(number<0)
        {
            negative++;
            negative_sum+=number;
        }
        else if(number==0)
        {
            zero++;
        }
    }
    printf("%d %d %d\n",positive,zero,negative);
    printf("%d %d\n",positive_sum,negative_sum);
    return 0;
}