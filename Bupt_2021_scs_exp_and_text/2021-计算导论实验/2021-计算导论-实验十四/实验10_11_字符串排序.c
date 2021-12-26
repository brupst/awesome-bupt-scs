/*1、设计函数char ** create1( int n ) ;，根据整数n创建一个长度为n的字符指针型动态一维数组，并返回动态数组第一个元素的地址。
2、设计函数char * create2( int n ) ;，根据整数n创建一个长度为n的字符型动态一维数组，并返回动态数组第一个元素的地址。
3、设计函数void sort( char** strArray , int size ) ; ，该函数可将字符指针数组strArray所指向的所有字符串按从小到大排列。
输入第一行为一个不超过200的整数n，代表待排序字符串的个数。然后输入n个字符串，每个字符串长度不会超过100。
输出为排序后的n个字符串，每个字符串占一行。*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define        MAX        101

char **    create1( int n ) ;
char *    create2( int n ) ;
void    sort( char** strArray , int size ) ; 

int main()
{
    char**    strArray ;
    int        n , i ;

    scanf("%d",&n) ;
    strArray = create1( n ) ; 
    if ( strArray != NULL ) 
    {
        for ( i = 0 ; i < n ; i++ ) 
        {
            strArray[i] = create2( MAX ) ;
            if ( strArray[i] == NULL ) return -1 ;
        }            
    }
    else return -1 ;//这里两个 return -1 都是无法获得内存时直接结束程序 

    getchar();//吃掉前边输入的回车符 

    for( i = 0 ; i < n ; i++ ) 
        gets(strArray[i]); //读入字符串 

    sort( strArray , n ) ; //排序 

    for( i = 0 ; i < n ; i++ ) 
        printf("%s\n",strArray[i]); //输出

    for ( i = 0 ; i < n ; i++ )  
        free(strArray[i]) ;
    free(strArray) ;

    return 0;
}

char **    create1( int n ) 
{
    char **a;
    a=(char **)malloc(sizeof(char *)*n);
    return a;
}

char *    create2( int n ) 
{
    char *a;
    a=(char *)malloc(sizeof(char)*n);
    return a;
}

void    sort( char** strArray , int size ) 
{
    int x,y;
    char *temp;
    for(x=0;x<size;x++)
    {
        for(y=0;y<size-1;y++)
        {
            if(strcmp(strArray[y],strArray[y+1])>0)
            {
                temp=strArray[y+1];
                strArray[y+1]=strArray[y];
                strArray[y]=temp;
            }
        }
    }
    return;
}