/*有表达式如下：
a / ( b * c - d )
请按要求计算 。
输入格式:
只有一行，为4个用空格分隔的浮点数，依次代表a,b,c,d（请用double 类型存储）。
输出格式:
如果除数为0，则输出error，否则输出该表达式的值（保留1位小数）。*/

#include<stdio.h>
int main()
{
  double a,b,c,d,num1,num2;
  scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
  num1=b*c-d;
  num2=a/(b*c-d);
  if((num1<=10e-6)&&(num1>=-10e-6))
  {
    printf("error");
  }
  else
  {
    printf("%.1f",num2);
  }
  return 0;
}