/*设计递归函数 int RecurBinarySearch( int a[] , int key , int left , int right ) ; 利用二分查找算法，
在升序排列的数组中查找值为key的数组元素的下标。如果数组中存在整数key，则返回下标；否则返回-1。假设数组a中的元素互不相同。
输入与输出要求：
首先输入两个整数n，m，分别代表数组a中元素的个数与需要查找的整数的个数，n（0<n<=2000000）与m(0<m<=100000)。然后分别输入n个整数和m个整数，
分别代表存放在数组中的数以及要查找的数。
输出为m个整数，分别为要查找的数在数组a中的下标，如果数组a中不存在某个数，则输出-1。数与数之间用空格分开，注意第m个数后没有空格而是换行符。*/

#include<stdio.h>

#define MAXN 2000000

int RecurBinarySearch( int a[] , int key , int left , int right ) ;

int main()
{
    int        a[MAXN];//这个数组比较大，如果在你的电脑中无法分配这么大的内存，请改小后测试。
    int        n , m , i , key ;

    scanf("%d %d",&n , &m );    
    for( i = 0 ; i < n ; i++ )
        scanf("%d", &a[i]);

    for( i =0 ; i < m ; i++ )
    {
        scanf("%d",&key);
        printf( "%d" , RecurBinarySearch( a , key , 0 , n - 1 ) );
        if ( i != m - 1 ) printf(" ") ;
        else printf("\n") ; 
    }

    return 0;
}

int RecurBinarySearch( int a[] , int key , int left , int right ) 
{
    int middle;
    int low=left;
    int high=right;
    if(left>right)
        return -1;
    else
    {
        while(low<=high)
        {
            middle=(low+high)/2;
            if(key==a[middle])
                return middle;
            else if(key>a[middle])
                return RecurBinarySearch(a,key,middle+1,right);
            else if(key<a[middle])
                return RecurBinarySearch(a,key,left,middle-1);
        }
    }
}