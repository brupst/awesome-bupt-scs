/*奶牛们有一个习惯，那就是根据自己的编号选择床号。如果一头奶牛的编号是a，并且有k张床，床号为0 到 k-1，那么它就会选择a % k号床作为它睡觉的地点。
显然，2头牛不能睡在一张床上。现在输入一些奶牛的编号，请你为她们准备一间卧室，使得需要的床的数量最少。
输入格式:
共两行，第一行为一个整数n（0<n<=100)，代表奶牛的个数。第二行为n个用空格分隔的整数，代表这n个奶牛的编号。这些编号的取值范围是1-3000，
且不存在编号相同的两头奶牛。
输出格式:
只有一行，为一个整数，代表所需最少的床位数k。*/

#include<stdio.h>
#define MAX 1000
int main()
{
    int bed[MAX]={0};
    int n,k,x,y;
    int judge=1;
    scanf("%d",&n);
    int cow[n];
    for(x=0;x<n;x++)
        scanf("%d",&cow[x]);
    for(k=n;;k++)
    {
        for(x=0;x<MAX;x++)
            bed[x]=0;
        for(x=0;x<n;x++)
            bed[cow[x]%k]++;
        for(x=0;x<k;x++)
        {
            if(bed[x]<=1)
                judge=1;
            else if(bed[x]>1)
            {
                judge=0;
                break;
            }
        }
        if(judge==1)
        {
            printf("%d",k);
            break;
        }
    }
    return 0;
}