/*请设计一个函数，参数为一个单词（字符串），假设max是单词中出现次数最多的字母的出现次数，min是单词中出现次数最少的字母的出现次数，
如果max-min是一个质数，则返回则max-min，否则返回-1。
注意：判断一个整数是否为质数的函数不需要实现，要求直接调用下边的函数来判断
int        isPrime( int n ) ;
该函数判断一个整数是否是质数，是则返回1，否则返回0。
测试程序输入：
只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。
测试程序输出：
如果输入单词的max-min是一个质数，输出max-min的值，否则输出-1。*/

#include<stdio.h>

#define        MAXLEN        110

int        isPrime( int n ) ;//判断一个整数是否是质数，是则返回1，否则返回0 
int        getResult( char word[] ) ;

int main()
{
    char    word[MAXLEN] ;

    scanf( "%s" , word ) ;            
    printf( "%d\n" , getResult( word ) );

    return 0;
}

int        getResult( char word[] ) 
{
    int a[256]={0};
    int x,max,min;
    for(x=0;word[x]!='\0';x++)
        a[(int)word[x]]++;
    for(x=0;x<256;x++)
    {
        if(a[x]!=0)
        {
            min=a[x];
            max=a[x];
            break;
        }
    }
    for(x=0;x<256;x++)
    {
        if(a[x]!=0)
        {
            if(min>=a[x])
                min=a[x];
            else if(max<=a[x])
                max=a[x];
        }
    }
    if(isPrime(max-min))
        return (max-min);
    else
        return -1;
}