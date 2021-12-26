/*s=1+a+pow(a,2)+...
其中a>0,n>0，且均为整数。 测试用例保证所有整数可以用int存储。 请写出递归求s的函数。
注意：此题要求递归求解，且不允许使用全局变量，其他方式不得分。*/

#include <stdio.h>

int    evaluation(int n,int a) ;
int main()
{
       int        n , a ; 

       scanf("%d%d",&n,&a);       
       printf("%d\n",evaluation(n,a));

    return 0;
}

int evaluation(int n,int a)
{
    if(n==0)
    {
        return a+1;
    }
    else
    {
        return 1+a*evaluation(n-1,a);
    }
}