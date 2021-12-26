/*一个整数的“反置数”指的是把该整数的每一位数字的顺序颠倒过来所得到的另一个整数。如果一个整数是以0结尾，那么在它的反置数当中，这些0就被省略掉了。
比如说，12345的反置数是 54321，而3200的反置数是23。请你设计一个求一个整数反置数的函数。
输入只有一行，为一个整数n(0<n)。
输出也只有一个整数，为n的反置数。测试用例保证所有整数都可以用int存储。*/

#include <stdio.h>

int reverse(int n) ; 

int main()
{
    int        n ;

    scanf( "%d" , &n );
    printf( "%d\n" , reverse(n) );

    return 0 ;
}

int reverse(int n)
{
    int x,y,result=0;
    while(n!=0)
    {
        x=n%10;
        result=10*result+x;
        n/=10;
    }
    return result;
}