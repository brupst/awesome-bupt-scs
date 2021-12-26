/*设计函数 void bubbleSort(int a[],int n);，实现对整型数组的排序。
输入第一行为一个整数n(0<n<=1000),代表待排序元素的个数。第二行是n个整数，每个整数都不会超过int型的存储范围，为待排序元素。
输出只有一行，为输入的n个待排序元素按从小到大排序后的结果。（建议采用起泡排序算法）
建议设计一个辅助函数:
函数功能：依次输出数组中各个元素，数与数之间用空格分开，最后一个数后没有空格而是换行符
参数说明：数组名，数组内元素个数
void outputData(int data[],int elementCount) ;
注：此题大家可以练习各种排序算法。*/

#include<stdio.h>

void bubbleSort(int a[],int n);

//输出数组中所有元素 
void outputData(int data[],int elementCount) ;

int main()
{
    int        n , i,    num[10010] ;

    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    bubbleSort(num,n) ; 
    outputData(num,n) ;
    return 0 ;
}

void bubbleSort(int a[],int n)
{
    int x,y,temp;
    for(y=0;y<n;y++)
    {
        for(x=0;x<n-1;x++)
        {
            if(a[x]>a[x+1])
            {
                temp=a[x+1];
                a[x+1]=a[x];
                a[x]=temp;
            }
        }
    }
}

void outputData(int data[],int elementCount) 
{
    int x;
    printf("%d",data[0]);
    for(x=1;x<elementCount;x++)
        printf("% d",data[x]);
    return;
}