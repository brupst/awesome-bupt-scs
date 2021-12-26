/*鸡有一个头两条腿，兔子有一个头4条腿，蜻蜓有一个头6条腿。没有例外。一个笼子里共有m个头，n条腿，问鸡、兔和蜻蜓各有多少？
输入格式:
只有一行，为两个正整数m和n，分别代表头的个数和腿的个数数。
输出格式:
有若干行，每一行为一组解，格式均为用空格分隔的三个整数，依次代表鸡的个数、解兔子的个数和蜻蜓的个数。多组解的输出顺序按解鸡的个数小到大排序。 
测试数据保证可以用int存储。*/

#include<stdio.h>
int main()
{
    int m,n,cock,rabbit,dragonfly;
    const int rabbit_legs=4;
    const int cock_legs=2;
    const int dragonfly_legs=6;

    scanf("%d%d",&m,&n);
    for(cock=0;cock<=(n/2);cock++)
    {
        for(rabbit=0;rabbit<=(n/4);rabbit++)
        {
            for(dragonfly=0;dragonfly<=(n/6);dragonfly++)
            {
                if(((cock+rabbit+dragonfly)==m)&&((rabbit_legs*rabbit+cock*cock_legs+dragonfly_legs*dragonfly)==n))
                {
                    printf("%d %d %d",cock,rabbit,dragonfly);
                }
            }
        }
    }
    return 0;
}