/*求下列函数值：
输入只有一行，依次为一个正整数n(1 <= n <= 200)，和一个浮点数x(0<x<100)。 输出只有一行，为所求得的函数值（保留3位小数）。
提示：C语言中开平方的函数原型为：double sqrt(double); ，可以在代码中使用
注意：此题要求递归求解，且不允许使用全局变量，否则没有分。*/

#include <stdio.h>
#include <math.h>

double fun( int n , double x );

int main()
{
    int        n;
    double    x;

    scanf( "%d%lf" , &n , &x );
    printf( "%.3f\n" , fun( n , x ) );

    return 0;
}

double fun( int n , double x )
{
    if(n==1)
        return sqrt(1+x);
    else
        return sqrt(n+fun(n-1,x));
}