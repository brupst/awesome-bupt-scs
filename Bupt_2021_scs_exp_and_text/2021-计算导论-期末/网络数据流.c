/*某公司收到了若干人员的信息，该信息是通过互联网以数据流的方式发过来的。这个数据流里全部是整数。每个人员信息的格式固定为三部分，
第一部分为一个整数，代表这个人的编号，第二个部分也是一个整数，代表后边信息的长度n，即这个人的信息包含多少个整数。
第三部分为n个整数，即这个人的信息。由于操作人员疏忽，这些人的信息并没有排序，现请你写一个函数将所有人员信息按编号排序并依次输出。
输入：共两行，第一行为一个整数n，代表信息流的总长度， 第二行为n个用空格分隔的整数，代表全部信息。
输出：若干行，每行为一个人员的信息。依次为编号，信息长度，及剩余全部信息，各个整数之间用一个空格分隔，行末无空格。具体见样例。
测试用例保证合法，且人员总数不超过1000。
注意：1、此题有内存限制。
2、排序算法要自己写，不允许使用系统提供的函数。
输入样例：
20
3 5 1 2 3 4 5 1 6 11 12 13 14 15 16 2 3 100 100 100
输出样例：
1 6 11 12 13 14 15 16
2 3 100 100 100
3 5 1 2 3 4 5*/

#include<stdio.h>
#include<stdlib.h>

#define        MAXLEN        500000
void  sortAndOutput(int *data , int size) ;

int main()
{
    int        data[MAXLEN];
    int        n, i;

    scanf( "%d" , &n );
    for ( i = 0 ; i < n ; i++ )
        scanf( "%d" , &data[i] );

    sortAndOutput( data, n ) ;

    return 0;    
}

void  sortAndOutput(int *data , int size) 
{
    int *ptr[1000];
    int end[1000];
    int *temp;
    int a=0;
    int b=0;
    int x,y,z=0;
    for(x=0;x<size;x++)
    {
        ptr[a]=&data[x];
        x++;
        x+=data[x];
        a++;
    }
    for(x=0;x<a;x++)
    {
        for(y=x+1;y<a;y++)
        {
            if(ptr[x][0]>ptr[y][0])
            {
                temp=ptr[x];
                ptr[x]=ptr[y];
                ptr[y]=temp;
            }
        }
    }
    for(x=0;x<a;x++)
    {
        printf("%d",ptr[x][0]);
        for(y=1;y<ptr[x][1]+1;y++)
            printf(" %d",ptr[x][y]);
        printf(" %d\n",ptr[x][ptr[x][1]+1]);
        z++;
    }
}