/*回文是指正读和反读都一样的数或文本段。例如，12321、55555、45554、11611都是回文数。输入一个长度不超过10位的整数n，判断它是否是回文数。
输入格式:
只有一个整数n，即待判断的数字。测试用例保证n可以用int存储。
输出格式:
当n为回文数时输出“Yes”，否则输出“No”。*/

#include<stdio.h>

long reserve(long n);

int main()
{
    long n;
    scanf("%ld",&n);
    if(n==reserve(n))
        printf("Yes");
    else
        printf("No");
    return 0;
}

long reserve(long n)
{
    long r,q=0;
    while(n>0)
    {
        r=n%10;
        n/=10;
        q=q*10+r;
    }
    return q;
}
