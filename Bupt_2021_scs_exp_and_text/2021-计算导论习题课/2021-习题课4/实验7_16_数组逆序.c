/*给定一个整数数组，请设计一个函数将数组内各元素逆序。
输入共两行，第一行为一个整数n(0<n<=100)，第二行为n个用空格分隔的整数（可以用int存储），要求依次存入一个数组中。
输出只有一行，为将逆序后的数组内各元素依次输出。*/

#include <stdio.h>

void reverseArray(int array[] , int size ); 

int main()
{
    int  i , n , array[100] ;

    scanf( "%d" , &n );
    for ( i = 0 ; i < n ; i++ )
        scanf( "%d" , &array[i] );
    reverseArray( array , n ) ;

    for ( i = 0 ; i < n - 1 ; i++ )    
        printf( "%d " , array[i] );    
    printf( "%d\n" , array[i] );

    return 0;
}

void reverseArray(int array[] , int size )
{
    int trans[size];
    int x,y;
    for(x=0;x<size;x++)
        trans[x]=array[size-x-1];
    for(x=0;x<size;x++)
        array[x]=trans[x];
    return 0;
}