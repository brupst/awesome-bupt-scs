/*数据清洗是指发现并纠正数据文件中可识别的错误的最后一道程序，包括检查数据一致性，处理无效值和缺失值等。小明去某公司实习，公司交给了他一个数据清洗的任务。
由于小明是实习生，所以数据清洗的算法公司已经给定，小明的任务仅仅是将清洗后合格的数据按原来的顺序存储并输出。
可是小明仍无法完成这个任务，聪明的你能帮帮他吗？
数据清洗的函数原型为：
int dataCleaning(int n);
这里参数n为待处理数据，如果该数据是正确的函数则返回1，如果该数据不正确则函数返回0。在你的函数中需要调用这个函数（不需要实现，直接调用即可）
来判断数据是否正确。*/

#include<stdio.h>

int getData(int source[] , int size , int target[] );

int dataCleaning(int n);

int main()
{
    int        source[110] , target[110];
    int        i , n , size ;

    scanf( "%d", &n ) ;
    for ( i = 0 ; i < n ; i++ )
        scanf( "%d", &source[i] ) ; 
    size = getData( source , n, target ) ; 
    for ( i = 0 ; i < size - 1 ; i++ )
        printf( "%d " , target[i] ) ;
    printf( "%d\n" , target[i] ) ;

    return 0;    
}

int getData(int source[] , int size , int target[] )
{
    int x,y=0,correct=0;
    for(x=0;x<size;x++)
    {
        if(dataCleaning(source[x]))
            correct++;
    }
    for(x=0;x<size;x++)
    {
        if(dataCleaning(source[x]))
        {
            target[y]=source[x];
            y++;
        }
    }
    return correct;
}