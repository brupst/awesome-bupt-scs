/*已知一个自然数，求n以内（不包括n）同时能被3与7整除的所有自然数之和的平方s。s保证在int范围之内。
输入格式:
只有一行，为自然数n。
输出格式:
只有一行，为一个自然数，代表计算结果。*/

#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,result;
    int sum=0;
    scanf("%d",&n);
    for(m=0;m<n;m++)
    {
        if((m%3==0)&&(m%7==0))
        {
            sum+=m;
            result=pow(sum,2);
        }
    }
    printf("%d",result);
    return 0;
}