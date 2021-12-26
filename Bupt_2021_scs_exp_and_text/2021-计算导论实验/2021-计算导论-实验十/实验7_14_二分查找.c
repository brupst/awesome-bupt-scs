/*设计函数 int BinarySearch(int a[],int n,int key);
利用二分查找算法，在升序排列的数组a的前n个元素中查找值为key的数组元素的下标。如果数组a中存在整数key，则返回下标；否则返回－1。假设数组a中的元素互不相同。
输入与输出要求：
首先输入两个整数n，m，分别代表数组a中元素的个数与需要查找的整数的个数，n（0<n<=2000000）与m(0<m<=100000)。然后分别输入n个整数和m个整数，
分别代表存放在数组中的数以及要查找的数。
输出m个整数，分别为要查找的数在数组a中的下标，如果数组a中不存在某个数，则输出-1。数与数之间用空格分开，注意第n个数后没有空格而是换行符。*/

#include<stdio.h>

//函数功能：二分查找
//函数参数：分别为被查找的数组，数组长度，所查找的元素
//函数返回值：如果找到，则返回该元素在数组中的下标，否则返回-1 
int BinarySearch(int a[],int n,int key) ; 

int main()
{
    int    num[2000000] ; //这个数组比较大，如果在你的电脑中无法分配这么大的内存，请改小后测试。
    int        n , m, i;    
    int        key ;

    scanf("%d%d",&n,&m); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;

    for( i = 0 ; i < m ; i++ ) 
    {
        scanf("%d",&key) ;
        printf("%d",BinarySearch(num,n,key)) ;
        if ( i != m - 1 ) printf(" ") ;
        else printf("\n") ;
    }
    return 0 ;
}

int BinarySearch(int a[],int n,int key) 
{
    int middle;
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        middle=(low+high)/2;
        if(key==a[middle])
            return middle;
        else if(key>a[middle])
            low=middle+1;
        else if(key<a[middle])
            high=middle-1;
    }
    return -1;
}