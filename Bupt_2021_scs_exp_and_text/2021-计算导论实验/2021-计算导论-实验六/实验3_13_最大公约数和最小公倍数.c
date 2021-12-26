/*已知两个正整数m和n，求其最大公约数和最小公倍数。
输入格式:
两个用空格分隔的正整数m和n。
输出格式:
只有一行，为两个用空格分隔的正整数，依次代表m和n的最大公约数和最小公倍数。测试用例保证m、n及其最小公倍数可以用int存储。*/

#include<stdio.h>

int gcd(int x,int y);
int lcm(int x,int y);

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d %d",gcd(x,y),lcm(x,y));
    return 0;
}

int gcd(int x,int y)
{
    return y ? gcd(y,x%y):x;
}

int lcm(int x,int y)
{
    int result,m;
    m=gcd(x,y);
    result=x/m*y;
    return result;
}
