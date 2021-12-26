/*任意给定一个n*m的矩阵，矩阵的行数为n,列数为m。你的任务是实现矩阵的转置，即行列互换。
输入格式:
第一行为两个整数n、m，代表矩阵的行数与列数，n、m的范围均是1—100。然后输入n*m个整数，即此矩阵的元素
输出格式:
经过矩阵转置得到的新矩阵，新矩阵占m行，n列。每行的每个元素用空格分隔，注意最后一个数的后面为换行符。*/

#include<stdio.h>
int main()
{
    int m,n,x,y,p,q;
    scanf("%d%d",&m,&n);
    int matrix[m][n];
    int trans_matrix[n][m];

    for(x=0;x<m;x++)
    {
        for(y=0;y<n;y++)
            scanf("%d",&matrix[x][y]);
    }
    for(x=0;x<m;x++)
    {
        for(y=0;y<n;y++)
            trans_matrix[y][x]=matrix[x][y];
    }
    for(x=0;x<n;x++)
    {
        for(y=0;y<m;y++)
        {
            if(y==0&&m!=1)
                printf("%d",trans_matrix[x][y]);
            else if(y<m-1)
                printf(" %d",trans_matrix[x][y]);
            else if(y==0&&m==1)
                printf("%d\n",trans_matrix[x][y]);
            else if(y==m-1)
                printf(" %d\n",trans_matrix[x][y]);
        }
    }
    return 0;
}