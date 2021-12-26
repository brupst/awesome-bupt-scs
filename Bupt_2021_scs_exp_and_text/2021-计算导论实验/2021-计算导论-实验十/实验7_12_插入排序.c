/*设计函数 void InsertSort(int a[],int n); 该函数使用插入排序算法，将数组a的前n个元素按照升序的方式排序。
插入排序算法描述如下：
初始序列：49 38 65 97 76 13 27 49
将元素(38) 插入合适位置： [38 49] 65 97 76 13 27 49
将元素(65) 插入合适位置： [38 49 65] 97 76 13 27 49
将元素(97) 插入合适位置： [38 49 65 97] 76 13 27 49
将元素(76) 插入合适位置： [38 49 65 76 97] 13 27 49
将元素(13) 插入合适位置： [13 38 49 65 76 97] 27 49
将元素(27) 插入合适位置： [13 27 38 49 65 76 97] 49
将元素(49) 插入合适位置： [13 27 38 49 49 65 76 97]
输入与输出要求： 首先输入一个整数n（1<=n<=1000），代表待排序元素的个数。然后输入n个整数，每个整数不会超过int型的存储范围。
输出为n-1行，依次为1到n-1趟排序后数组内各个元素。每行输出的顺序为a[0]至a[n-1]，数与数之间用空格分开，注意第n个数后没有空格而是换行符。*/

#include<stdio.h>

//插入排序（升序） 
//参数说明：数组，数组中已有元素个数 
void InsertSort(int a[],int n);

int main()
{
    int        n , i,    num[1000] ;

    scanf( "%d" , &n ); 
    for( i = 0 ; i < n ; i++ ) 
        scanf( "%d", &num[i] ) ;
    InsertSort( num , n ) ; 
    return 0 ;
}

void InsertSort(int a[],int n)
{
    int x,y,max,min,temp,z;
    for(x=1;x<n;x++)
    {
        min=a[0];
        max=a[x-1];
        if(max==a[x])
            continue;
        else
        {
            for(y=x-1;y>=0;y--)
            {
                if(a[x]<=min)
                {
                    z=y;
                    temp=a[x];
                    for(z;z>=0;z--)
                        a[z+1]=a[z];
                    a[0]=temp;
                    break;
                }
                else if(a[y-1]<=a[x]&&a[x]<=a[y])
                {
                    z=x-1;
                    temp=a[x];
                    for(z;z>=y;z--)
                        a[z+1]=a[z];
                    a[y]=temp;
                    break;
                }
            }
        }
        printf("%d",a[0]);
        for(y=1;y<n-1;y++)
            printf(" %d",a[y]);
        printf(" %d\n",a[n-1]);
    }
}