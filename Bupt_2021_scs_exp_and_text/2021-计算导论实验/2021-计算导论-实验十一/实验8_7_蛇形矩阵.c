/*蛇形矩阵是一个n*n的矩阵，将整数1到n*n按照蛇形的顺序装入一个 n*n 的蛇形矩阵中，如样例所示分别为5阶和10阶蛇形矩阵。
输入格式:
只有一行，为一个整数n，代表蛇形矩阵的阶数，n的范围是1—100。
输出格式:
共n行，为蛇形矩阵。每行的每个元素用空格分隔，注意最后一个数的后面为换行符。*/

#include<stdio.h>
int main()
{
	int n,a[100][100]={1},i=0,j=0,k=1;
	scanf("%d",&n);
	//定义四种状态：k=1向下走，k=2向右上方走，k=3向右走，k=4向左下角走//
	while(i!=n-1 || j!=n-1)
	{
		if(k==1)
		{
			a[i+1][j]=a[i][j]+1;
			i++;
			if(j==0)
			  k=2;
			else if(j==n-1)
			  k=4;
		}
		else if(k==2)
		{
			a[i-1][j+1]=a[i][j]+1;
			i--,j++;
			if(i==0&&j!=n-1)
			  k=3;
			else if(j==n-1)
			  k=1;
			else
			  k=2;
		}
		else if(k==3)
		{
			a[i][j+1]=a[i][j]+1;
			j++;
			if(i==0)
			  k=4;
			else if(i==n-1)
			  k=2;
		}
		else if(k==4)
		{
			a[i+1][j-1]=a[i][j]+1;
			i++,j--;
			if(j==0&&i!=n-1)
			  k=1;
			else if(i==n-1)
			  k=3;
			else
			  k=4; 
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
        {
            if(j==0)
                printf("%d",a[i][j]);
            else if(j<n-1)
                printf(" %d",a[i][j]);
            else if(j=n-1)
                printf(" %d\n",a[i][j]);
        }
	} 
	return 0;
}