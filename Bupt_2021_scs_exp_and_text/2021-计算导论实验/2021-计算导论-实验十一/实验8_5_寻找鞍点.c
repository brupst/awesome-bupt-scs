/*任意给定一个n*m的矩阵，矩阵的行数为n,列数为m。你的任务是寻找该矩阵的鞍点。一个矩阵的鞍点即该位置上的元素在所在行上最大，在所在列上最小。
有的矩阵也可能没有鞍点。不难证明，如果一个矩阵有鞍点，那么这个鞍点一定是唯一的。
如果某个矩阵只有1行（1列），则默认该行上的所有元素满足列上最小（行上最大）的要求。
例如矩阵M：
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20
该矩阵的鞍点为M[0][4]=5，该数在第0行最大，在第4列最小。
测试用例保证同行或同列内没有相等的值。
输入格式:
共n+1行，第一行为用空格分隔的两个整数n、m，代表矩阵的行数与列数，n、m的范围均是1—100。后边n行为n*m个整数，即此矩阵的元素。
具体见样例。测试用例保证所有整数可以用int存储。
输出格式:
只有一行，如果找到该矩阵的鞍点则输出“The saddle point is (x,y)=v.”，x为该鞍点所在的行，y为该鞍点所在的列，v为该位置上元素的值；
如果该矩阵没有鞍点，则输出“There is no saddle point in the matrix.”。*/

#include<stdio.h>
#define MAX 100

int FindMax(int a[][MAX],int m,int x);
int FindMin(int a[][MAX],int n,int y);

int main()
{
    int n,m,x,y,q;
    scanf("%d%d",&n,&m);
    int ma[MAX][MAX];
    for(x=0;x<n;x++)
    {
        for(y=0;y<m;y++)
            scanf("%d",&ma[x][y]);
    }
    for(x=0;x<n;x++)
    {
        y=FindMax(ma,m,x);
        q=FindMin(ma,n,y);
        if(q==x)
        {
            printf("The saddle point is (%d,%d)=%d.",q,y,ma[q][y]);
            return 0;
        }
    }
    printf("There is no saddle point in the matrix.");
    return 0;
}

int FindMax(int a[][MAX],int m,int x)
{
    int max,y;
    max=a[x][0];
    for(y=0;y<m;y++)
    {
        if(a[x][y]>max)
            max=a[x][y];
    }
    for(y=0;y<m;y++)
    {
        if(max==a[x][y])
            return y;
    }
}

int FindMin(int a[][MAX],int n,int y)
{
    int min,x;
    min=a[0][y];
    for(x=0;x<n;x++)
    {
        if(a[x][y]<min)
            min=a[x][y];
    }
    for(x=0;x<n;x++)
    {
        if(min==a[x][y])
            return x;
    }
}