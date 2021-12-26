/*已知一个整数n，你要根据n打印出n阶的实心菱形。
输入格式:
只有一个整数n(0<n<40，代表要打印的菱形阶数)。测试用例保证合法。
输出格式:
n阶实心菱形(占2乘n-1行)。*/

#include<stdio.h>
int main()
{
  int x,y,line,N,k;
  scanf("%d",&line);
  for(x=1;x<=line;x++)
  {
    N=2*x-1;
    for(y=line;y>x;y--)
    {
      printf(" ");
    }
    for(k=1;k<=N;k++)
    {
      printf("*");
    }
    if(x!=0)
    printf("\n");
  }
  x-=2;
  for(x;x>0;x--)
  {
    N=2*x-1;
    for(y=x;y<line;y++)
    {
      printf(" ");
    }
    for(k=N;k>0;k--)
    {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}