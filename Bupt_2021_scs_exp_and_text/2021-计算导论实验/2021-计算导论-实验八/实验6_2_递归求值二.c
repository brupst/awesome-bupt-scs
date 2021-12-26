/*现有序列： s = a+a+3+a+6+…+a+3*n请写出递归求s的程序。*/
/*输入只有一行，为两个用空格分隔正整数，分别代表n(0<n) 和 a(1<a),输出也只有一行，为此情况下s的值。*/

#include <stdio.h>

int getSum(int n , int a) ;

int main()
{
       int        n , a ; 

       scanf( "%d%d" , &n , &a );       
       printf( "%d\n" , getSum( n , a ) );

    return 0;
}

int getSum(int n , int a)
{
    int result;
    if(n==0)
    {
        return a;
    }
    else
    {
        result=getSum(n-1,a)+a+3*n;
        return result;
    }
}