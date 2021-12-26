/*有n个互不相同的整数，存储在数组中。在这n个整数中查找m个整数，如果存在，则打印出与之相邻的整数；否则就显示无此数。
输入格式:
共4行，第一行为一个整数n（0<n<=1000），第二行为用空格分隔的n个整数。第三行为一个整数 m(0<m<=100)，
代表查询次数。第四行为用空格分隔的m个整数。测试用例保证所有整数可以用int存储。
输出格式:
共m行，依次对应输入m次查询结果，每次的查询结果中可能有一个数、两个数或没有数。若没有数则输出“NULL”。具体见样例。*/

#include<stdio.h>
int main()
{
    int n,x,m,find,y,judge=0;
    scanf("%d",&n);
    int number[n];
    if(n==1)
        printf("NULL\n");
    else
    {
        for(x=0;x<n;x++)
            scanf("%d",&number[x]);
        scanf("%d",&m);
        for(x=0;x<m;x++)
        {
            scanf("%d",&find);
            judge=0;
            for(y=0;y<n;y++)
            {
                if(find==number[y]&&y>0&&y<n-1)
                    printf("%d %d\n",number[y-1],number[y+1]);
                else if(find==number[y]&&y==0)
                    printf("%d\n",number[1]);
                else if(find==number[y]&&y==n-1)
                    printf("%d\n",number[y-1]);
                else
                {
                    judge++;
                }
            }
            if(judge==n)
                printf("NULL\n");
        }
    }
    return 0;
}