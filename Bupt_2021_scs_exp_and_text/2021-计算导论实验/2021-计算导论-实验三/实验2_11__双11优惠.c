/*双十一快到了，网上的各个商家纷纷推出各种优惠活动，某商家的优惠方式为满100减30，满200减70，满300减110，满400减160。

请你写一段程序，根据给定条件，计算用户某单实际该付多少钱。

输入格式:
第一行为一个整数t代表测试数据组数。

后边是t行测试数据，每行均为若干个用空格分隔的整数，其中第一个整数为n，代表用户买的商品的个数，后边为n个正整数，分别代表这n件商品的价格。

输出格式:
为t行，每行依次对应输入的t行测试数据用户实际付钱的计算结果。测试用例保证所有整数（包括求和的结果）可以用int存储。*/


#include<stdio.h>

int calculator(int number_of_goods);
void judgement(int total_price);

int main()
{
  int chart,x,total_price,a;
  scanf("%d",&chart);
  for(x=1;x<=chart;x++)
  {
    scanf("%d",&a);
    total_price=calculator(a);
    judgement(total_price);
  }
  return 0;
}

int calculator(int number_of_goods)
{
  int y,single_price;
  int sum=0;
  for(y=1;y<=number_of_goods;y++)
  {
    scanf("%d",&single_price);
    sum+=single_price;
  }
  return sum;
}

void judgement(int total_price)
{
  if((total_price>=100)&&(total_price<200))
  {
    printf("%d\n",total_price-30);
  }
  else if((200<=total_price)&&(total_price<300))
  {
    printf("%d\n",total_price-70);
  }
  else if((300<=total_price)&&(total_price<400))
  {
    printf("%d\n",total_price-110);
  }
  else if(total_price>=400)
  {
    printf("%d\n",total_price-160);
  }
  else
  {
    printf("%d\n",total_price);
  }
  return;
}

