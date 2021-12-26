/*任意给定一个n*n的矩阵，矩阵的行数与列数均为n。你的任务是通过行变换，使得矩阵每行元素的平均值按递增顺序排列。
如果出现有的行平均值相同的情况，则按照原顺序输出。
输入格式:
共n+1行，第一行为一个整数n代表矩阵的行数（列数），n的范围是1—100。后边n行为n*n个整数，即此矩阵的元素。矩阵元素的绝对值不会超过1000000。
输出格式:
共n行，为经过行变换后的新矩阵。每行的每个元素用空格分隔，注意最后一个元素后为换行符。具体见样例。*/

#include<stdio.h>

void trans(float * a,float *b);

int main()
{
    int n,x,y,p,q;
    scanf("%d",&n);
    float a[n][n+1];
    float * intptr[n];
    for(x=0;x<n;x++)
    {
        for(y=0;y<n+1;y++)
            a[x][y]=0;
    }
    for(x=0;x<n;x++)
    {
        for(y=1;y<n+1;y++)
        {
            scanf("%f",&a[x][y]);
            a[x][0]+=a[x][y];
        }
        a[x][0]/=n;
        intptr[x]=a[x];
    }
    for(p=0;p<n-1;p++)
    {
        for(q=0;q<n-1;q++)
        {
            if(*intptr[q]>*intptr[q+1])
                trans(&intptr[q],&intptr[q+1]);
        }
    }
    for(x=0;x<n;x++)
    {
        for(y=1;y<n+1;y++)
        {
            if(y==1)
                printf("%.f",intptr[x][y]);
            else if(y<n)
                printf(" %.f",intptr[x][y]);
            else if(y==n)
                printf(" %.f\n",intptr[x][y]);
        }
    }
    return 0;
}

void trans(float * a,float *b)
{
    float temp;
    temp=*b;
    *b=*a;
    *a=temp;
    return;
}