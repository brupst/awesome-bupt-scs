/*设计函数 void SelectSort(int a[],int n); 使用选择排序算法对数组a的前n个元素按照升序的方式排序。
选择排序算法描述如下： 从a[0]到a[n-1]这段元素中找最小元素a[min]，a[0]和a[min]交换；接着，从a[1]到a[n -1]这段元素中找最小元素a[min]，
a[1]和a[min]交换；依次类推，直到从a[n－2]到a[n -1]这段元素中找最小元素a[min]，a[n－2]和a[min]交换。
输入：首先输入一个整数n(1<n<=1000)，代表待排序元素的个数。然后是n个整数，每个整数不会超过int型的存储范围
输出为n-1行，依次为1到n-1趟排序后数组内各个元素。每行输出的顺序为a[0]至a[n-1]，数与数之间用空格分开，注意第n个数后没有空格而是换行符。
建议设计两个辅助函数:
函数功能：找数组中的最小值元素，并返回其下标
参数说明：数组名，查找起始位置下标，查找终止位置下标
int findMin(int data[], int startLoc, int endLoc) ;
函数功能：依次输出数组中各个元素，数与数之间用空格分开，最后一个数后没有空格而是换行符
参数说明：数组名，数组内元素个数
void outputData(int data[],int elementCount) ;*/

#include<stdio.h>

//选择排序（升序） 
//参数说明：数组，数组中已有元素个数 
void selectSort(int data[],int elementCount) ;

//函数功能：找数组中的最小值元素，并返回其下标 
//参数说明：数组名，查找起始位置下标，查找终止位置下标
int findMin(int data[], int startLoc, int endLoc) ; 

//输出数组中所有元素 
//参数说明：数组，数组中已有元素个数 
void outputData(int data[],int elementCount) ;

int main()
{
    int        n , i,    num[1010] ;

    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    selectSort(num,n) ; 
    return 0 ;
}

void selectSort(int data[],int elementCount) 
{
    int x,temp,y;
    for(x=0;x<elementCount-1;x++)
    {
        temp=data[x];
        y=findMin(data,x,elementCount);
        data[x]=data[y];
        data[y]=temp;
        outputData(data,elementCount);
    }
    return;
}

int findMin(int data[], int startLoc, int endLoc) 
{
    int min=data[startLoc];
    int x,count;
    for(x=startLoc;x<endLoc;x++)
    {
        if(min>data[x])
        {
            min=data[x];
            count=x;
        }
    }
    for(x=startLoc;x<endLoc;x++)
    {
        if(min==data[x])
        {
            return x;
        }
    }
}

void outputData(int data[],int elementCount) 
{
    int x;
    printf("%d",data[0]);
    for(x=1;x<elementCount-1;x++)
        printf(" %d",data[x]);
    printf(" %d\n",data[elementCount-1]);
    return;
}