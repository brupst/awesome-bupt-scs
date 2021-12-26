/*有一堆小球，被分别放到n个桶里，如果每个桶里的小球的个数相等，则剩一个小球。此时如果把其中一个桶里的小球再按同样的规则放到n个桶里，
发现还是剩一个小球。如果按照此种方式能做m次，则小球的数量最少是多少？
输入格式:
为两个用空格分隔的整数n(1<n)，m(0<m)。测试用例合法且保证所有整数可以用int存储。
输出格式:
为一个整数，代表小球最少有多少个*/

#include<stdio.h>                
int main()
{
    int n,m;
    int x,ans;
    scanf("%d%d",&n,&m);
    ans=1+n;
    for(x=1;x<m;x++)
    {
        ans=ans*n+1;
    }
    printf("%d",ans);
    return 0;
}
/////////////////////////////递推
#include<stdio.h>
#include<math.h>
int main()
{
    int result,n,m;
    scanf("%d%d",&n,&m);
    result=(pow(n,m+1)-1)/(n-1);
    printf("%d",result);
    return 0;
}
//////////////////////////////通项公式
#include<stdio.h>

int result(int n,int m);

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d",result(n,m));
    return 0;
}

int result(int n,int m)
{
    if(m==0)
        return 1;
    else
        return 1+n*result(n,m-1);
}
//////////////////////////////////////递归