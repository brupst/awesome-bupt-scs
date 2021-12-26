/*Collatz conjecture，又称为奇偶归一猜想、3n＋1猜想：是指对于每一个正整数，如果它是奇数，则对它乘3再加1，如果它是偶数，则对它除以2，
如此循环，最终都能够得到1。
请设计递归函数计算3n＋1猜想。
函数每调用一次，输出调用时的参数n。如果n不等于1，继续调用函数计算，直到等于1为止。
输出的中间结果以一个空格分隔，最后一个数1后边无空格，为换行符。
测试数据保证所有整数可以用int类型存储。*/

#include<stdio.h>

void collatz(int n);
int main()
{
    int n;

    scanf("%d", &n);
    collatz(n);

    return 0;
}

void collatz(int n)
{
    printf("%d ",n);
    if(n==1)
    {
        printf("1");
        return;
    }
    else if(n%2==0)
    {
        return collatz(n/2);
    }
    else if(n%2==1)
    {
        return collatz(3*n+1);
    }
}