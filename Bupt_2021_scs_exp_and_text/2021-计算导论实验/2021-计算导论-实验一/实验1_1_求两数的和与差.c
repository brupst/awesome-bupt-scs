/*输入两个整数，求这两个整数的和与差并输出。和为两数相加，差为第一个输入的数减去第二个输入的数。
输入格式:
为用空格分隔的两个整数，并且这两个整数以及它们的和、差均不会超过int类型的存储范围。
输出格式:
只有一行，假设输入了1与2这两个整数，那么输出是“The sum is 3 and the difference is -1.”*/

#include<stdio.h>
int main()
{
    int num1,num2,sum,difference;
    scanf("%d%d",&num1,&num2);
    sum=num1+num2;
    difference=num1-num2;
    printf("The sum is %d and the difference is %d.",sum,difference);
    return 0;
}