/*双十一快到了，小伙伴们免不了在网上买些东西，有时呢免不了要付快递费。关于快递费的计算某快递公司规定：
首重为5公斤，也就是说5公斤以内（包括5公斤）价格一样，根据距离不同快递费分别为：200公里（包括200公里）以内：6元；
800公里以内（包括800公里）8元；800公里以外10元；续重（超过5公斤以后），每超出1公斤（包括1公斤）以内，200公里以内（包括200公里）加2元；
800公里以内（包括800公里）加4元；800公里以外加5元；
请你写一段程序，根据给定条件，计算某包裹的快递费。
输入格式:
第一行为一个整数t（0<t<10）代表测试数组组数。 后边是t行测试数据，每行均为用空格分隔的两个整数，分别代表快递的公斤数和发送的公里数。测试用例保证合法。
输出格式:
为t行，每行依次对应输入的t行测试数据的快递费计算结果。*/

#include<stdio.h>
int main()
{
    int t,x,y,weight,distance,total;
    scanf("%d",&t);
    for(x=0;x<t;x++)
    {
        scanf("%d%d",&weight,&distance);
        if(weight<=5)
        {
            if(200>=distance)
                total=6;
            else if (distance>200&&distance<=800)
                total=8;
            else if(distance>800)
                total=10;
        }
        else if(weight>5)
        {
            if(200>=distance)
                total=6+(weight-5)*2;
            else if (distance>200&&distance<=800)
                total=8+(weight-5)*4;
            else if(distance>800)
                total=8+(weight-5)*5;
        }
        printf("%d\n",total);
    }
    return 0;
}