/*美国邮票的面值共有1, 10, 21, 34, 70, 100, 350, 1225, 1500九种（单位为美分）。现给定一个邮资的价格n（以美分为单位），
如果规定所贴邮票面值总和必须等于n，请输出最少要贴几张邮票。为了简化程序，我们假设只有1, 10, 21, 34四种面值。
输入格式:
为一个整数n。(0<n<1000)。测试用例保证合法且均可以用int存储。
输出格式:
也是一个整数，为所贴邮票的张数。*/

#include<stdio.h>
int main()
{
    int n;
    int number;
    int min;
    int a,b,c,d;
    scanf("%d",&n);
    min=n;
    for(a=0;a<=(n/a);a++)
    {
        for(b=0;b<=n/b;b++)
        {
            for(c=0;c<=(n/c);c++)
            {
                for(d=0;d<=(n/d);d++)
                {
                    if(a+10*b+21*c+34*d==n)
                    {
                        number=a+b+c+d;
                        if(min>=number)
                        {
                            min=number;
                        }
                    }
                }
            }
        }
    }
    printf("%d",min);
    return 0;
}