/*将整型数组内元素循环向左移若干位置。循环向左移位含义如下：
比如，原始数组a[0],a[1]...a[9]内元素依次为：1 2 3 4 5 6 7 8 9 10，循环向左移1位后，则a[0],a[1]...a[9]内元素依次为：
2 3 4 5 6 7 8 9 10 1，循环向左移2位后，则a[0],a[1]...a[9]内元素依次为：3 4 5 6 7 8 9 10 1 2。依次类推。*/

#include <stdio.h>
#include <stdlib.h>

void shift(int *array , int num , int size ) ;

int main()
{
    int        i , n , p , array[100] ;

    scanf(" %d%d" , &n , &p ) ;//测试用例保证0<p<n<=100
    for( i = 0 ; i < n ; i++ )
        scanf( "%d" , &array[i] ) ;//测试用例保证所有输入可以用整型存储

    shift( array , p , n ) ;//向左移p位
    for( i = 0 ; i < n - 1 ; i++ )
        printf( "%d " , array[i] ) ;
    printf( "%d\n" , array[i] ) ;

    return 0;    
}

void shift(int *array , int num , int size ) 
{
    int temp[2*size];
    int x;
    for(x=0;x<size;x++)
    {
        temp[x]=array[x];
        temp[x+size]=array[x];
    }
    if(num>size)
        num%=size;
    for(x=num;x<size+num;x++)
        array[x-num]=temp[x];
    return;
}