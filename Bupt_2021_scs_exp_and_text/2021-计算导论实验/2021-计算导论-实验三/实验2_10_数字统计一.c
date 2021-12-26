/*请你写一段程序，统计各类数字的占比。
提示：输出%时需要用%%才能输出。
输入格式:
只有一行，为用空格分隔的若干整数，最后一个整数为0。测试用例保证输入中只包含这一个0。
输出格式:
共三行，依次分别输出3、5、7的倍数的占比（如果某个数同时为多个数的倍数，如15，70等，则不参与统计，但要计到总数中）。
占比采用百分数形式，且保留2位小数。这里的占比指的是这类数字的数量跟所有数字的总数（不包括最后的0）比。测试用例保证所有整数可以用int存储。*/

#include<stdio.h>
int main()
{
  double three=0;
  double five=0;
  double seven=0;
  double total=0;
  int input;
  double three_radio,five_radio,seven_radio;
  while((scanf("%d",&input))==1&&(input!=0))
  {
    total++;
    if((input%5==0)&&(input%7==0)&&(input%3==0))
    {
      three--;
      five--;
      seven--;
    }
    else if((input%3==0)&&(input%5==0))
    {
      three--;
      five--;
    }
    else if((input%3==0)&&(input%7==0))
    {
     three--;
     seven--;
    }
    else if((input%5==0)&&(input%7==0))
    {
      five--;
      seven--;
    }
    if(input%3==0)
      three++;
    if(input%5==0)
      five++;
    if(input%7==0)
      seven++;
  }
  three_radio=100*three/total;
  five_radio=100*five/total;
  seven_radio=100*seven/total;
  printf("%.2f%%\n",three_radio);
  printf("%.2f%%\n",five_radio);
  printf("%.2f%%\n",seven_radio);
  return 0;
}
