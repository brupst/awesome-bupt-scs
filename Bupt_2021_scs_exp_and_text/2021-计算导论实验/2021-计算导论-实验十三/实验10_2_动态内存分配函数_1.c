/*1、设计函数int * create(int n) ;，根据整数n创建一个长度为n的整型动态一维数组，并返回动态数组第一个元素的地址。
2、设计函数 void cal(int * array, int size) ;该函数可计算array 所指向的动态一维数组中存储的size个整数的和及平均值，同时寻找其中的最大值、最小值。
输入共两行，第一行为一个整数n(0<n<100)。第二行为n个用空格分隔的整数。第一行在主函数中输入，第二行需在函数cal中输入，
并存储在 array 所指向的动态一维数组中。
输出共5行，前四行依次为和、平均值（精确到小数点后两位）、最大值、最小值。最后一行按原样输出输入的那n个整数。
前四行需在函数cal中输出，最后一行由主函数输出。
测试数据保证所有整数可以用int型存储。出题者存储浮点数时用的是 float。*/

#include<stdio.h>
#include<stdlib.h>


int * create(int n) ;
void cal(int * array, int size) ;

int main()
{
    int * array , n , i ;

    scanf( "%d", &n );

    array = create(n) ;
    if ( array == NULL )
        return -1 ; //这里的return是因为没有获得内存而直接结束程序。

    cal( array, n) ;
    for ( i = 0 ; i < n ; i++ )
    {
        printf("%d" , *(array+i) ) ;
        if ( i == n - 1 ) printf("\n") ;
        else printf(" ") ;
    }     

    free(array) ;

    return 0;
}

int * create(int n) 
{
    int *a;
    a=(int*)malloc(sizeof(int)*n);
    return a;
}

void cal(int * array, int size) 
{
    int x;
    int max,min;
    float average=0;
    float sum=0;
    for(x=0;x<size;x++)
    {
        scanf("%d",&array[x]);
        sum+=array[x];
    }
    average=(sum/size);
    max=min=array[0];
    for(x=0;x<size;x++)
    {
        if(max<=array[x])
            max=array[x];
        else if(min>=array[x])
            min=array[x];
    }
    printf("%.f\n%.2f\n%d\n%d\n",sum,average,max,min);
    return;
}