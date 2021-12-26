/*现有一个矩阵，请你写程序求出某个数周围数字的和。这里我们规定，矩阵的左上角坐标为（1，1），它右边一行的数的坐标依次为（1，2）、（1，3）等等，
它下边一列的数的坐标依次为（2，1）、（3，1）等等，其余坐标以此类推。
输入格式:
第一行为两个整数m,n(1<m,n<10)，分别代表矩阵的行和列数。 接下来是m行n列整数，最后一行是两个整数x,y，分别代表指定的坐标。
输出格式:
为一个整数，为指定坐标周围的数字的和。需要注意的是当指定坐标在矩阵中间时，它周围有8个数，当它在矩阵边缘时它周围有5个数，
当它在矩阵角上时它周围只有3个数。测试用例保证合法且所有整数可以用int存储。*/

#include<stdio.h>
int main()
{
    int m,n,x,y,result;
    int locate[2];
    scanf("%d%d",&m,&n);
    int martix[m+2][n+2];
    for(x=0;x<m+2;x++)
    {
        for(y=0;y<n+2;y++)
            martix[x][y]=0;
    }
    for(x=1;x<m+1;x++)
    {
        for(y=1;y<n+1;y++)
            scanf("%d",&martix[x][y]);
    }
    scanf("%d%d",&locate[0],&locate[1]);
    result=martix[locate[0]-1][locate[1]-1]+martix[locate[0]][locate[1]+1]+martix[locate[0]][locate[1]-1]+martix[locate[0]+1][locate[1]]+martix[locate[0]-1][locate[1]]+martix[locate[0]+1][locate[1]+1]+martix[locate[0]+1][locate[1]-1]+martix[locate[0]-1][locate[1]+1];
    printf("%d",result);
    return 0;
}