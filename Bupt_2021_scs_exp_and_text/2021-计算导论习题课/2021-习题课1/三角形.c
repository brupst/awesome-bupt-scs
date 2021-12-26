/*有一根绳子的长度为n（3<=n<1000且为整数），将该绳子分成三段，每段的长度为正整数，请计算由这三段绳子组成的三角形个数。
输入格式:
只有一个整数代表n，测试用例保证合法。
输出格式:
只有一个整数，为能组成的三角形的个数。*/

#include<stdio.h>
int main()
{
    int x,y,z,N;
    int count=0;
    scanf("%d",&N);
    if(N%2==0)
    {
        for(x=1;x<(N/2);x++)
        {
            for(y=x;y<(N/2);y++)
            {
                for(z=y;z<(N/2);z++)
                {
                    if((x+y>z)&&(x+y+z==N))
                    {
                        count++;
                    }
                }
            }
        }
    }
    else
    {
        for(x=1;x<(N/2)+1;x++)
        {
            for(y=x;y<(N/2)+1;y++)
            {
                for(z=y;z<(N/2)+1;z++)
                {
                    if((x+y>z)&&(x+y+z==N))
                    {
                        count++;
                    }
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}