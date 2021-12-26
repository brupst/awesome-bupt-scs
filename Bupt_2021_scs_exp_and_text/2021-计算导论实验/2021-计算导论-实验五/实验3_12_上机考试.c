/*计算导论与程序设计某次上机考试共出了4道题，其中每名同学都至少做对了一道题。根据已知条件求做对了2、3、4题的可能的人数。。
输入格式:
只有一行，为两个用空格分隔的正整数m和n，分别代表参加考试的总人数和总的解题数。
输出格式:
有若干行，每一行为一组解，格式均为用空格分隔的三个整数，依次代表解2题的人数，解3题的人数和解4题的人数。
多组解的输出顺序按解2题人数由小到大排序，如果解2题的人数相同则按解3题的人数由小到大排序。所有测试数据保证可以用int存储。*/

#include<stdio.h>
int main()
{
    int two,three,four,m,n;
    scanf("%d%d",&m,&n);
    for(two=0;two<=(n-m);two++)
    {
        for(three=0;(2*three)<=(n-m);three++)
        {
            for(four=0;(3*four)<=(n-m);four++)
            {
                if((two+three+four==m)&&((two+three*2+four*3)==(n-m)))
                {
                    printf("%d %d %d",two,three,four);
                }
            }
        }
    }
    return 0;
}