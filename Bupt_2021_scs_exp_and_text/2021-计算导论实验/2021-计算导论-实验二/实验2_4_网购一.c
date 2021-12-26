/*某电商规定，如果订单商品总价小于20元，则付快递费10元；如果订单商品总价大于等于20元且小于30元，则付快递费8元；
如果订单商品总价大于等于30元且小于40元，则付快递费5元；如果某订单商品总价大于等于40元，则包邮。现某订单共4件商品，请你算一下该订单实付多少。
输入格式:
只有一行，为四个用空格分隔的正整数，代表4件商品的价格。
输出格式:
为一个整数，为客户实际需要支付的钱数。测试用例保证输入合法，且所有整数可以用int型存储。*/

#include<stdio.h>
int main()
{
  int num1,num2,num3,num4,sum,price;
  scanf("%d%d%d%d",&num1,&num2,&num3,&num4);
  sum=num1+num2+num3+num4;
  if(sum<20)
  {
    price=sum+10;
    printf("%d",price);
  }
  else if((sum>=20&&sum<30)==1)
  {
    price=sum+8;
    printf("%d",price);
  }
  else if((sum>=30&&sum<40)==1)
  {
    price=sum+5;
    printf("%d",price);
  }
  else printf("%d",sum);
  return 0;
}