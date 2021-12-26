/*1、设计函数char ** create1(int n) ;，根据整数n创建一个长度为n的字符型指针动态一维数组，并返回动态数组第一个元素的地址。
2、设计函数void create2( char ** strPtr , int n ) ;，为字符型指针动态一维数组strPtr中的每一个元素创建一个长度为n+1字符型动态一维数组。
参数n为字符型指针动态一维数组strPtr的长度。
3、设计函数void fill(char ** strPtr , int n) ;按要去将相应的字符填入二维动态数组strPtr中。具体格式见样例。
输入只有一行，为一个整数n（0<=n<=40）。
输出共2*n+1行，具体见样例。*/

#include<stdio.h>
#include<stdlib.h>

char ** create1(int n) ;
void create2( char ** strPtr , int n ) ;
void fill(char ** strPtr , int n) ;


int main()
{
    int        n, i, j;
    char**    strPtr ;

    scanf("%d", &n );
    strPtr = create1( n * 2 + 1 ) ;
    create2( strPtr ,  n * 2 + 1 ) ;
    fill(strPtr , n) ;

    for (i = 0; i < 2 * n + 1; i++)
    {
        printf("%s\n" , strPtr[i]);
    }

    for ( i = 0 ; i < n * 2 + 1 ; i++ )
        free(strPtr[i]) ;
    free(strPtr) ;

    return 0;
}

char ** create1(int n) 
{
    char **a;
    int x;
    a=(char**)malloc(sizeof(char*)*n);
    return a;
}

void create2( char ** strPtr , int n ) 
{
    int x;
    for(x=0;x<n;x++)
        strPtr[x]=(char*)malloc(sizeof(char)*(n+1));
    return;
}

void fill(char ** strPtr , int n) 
{
    int x,y,z,q=-1;
    for(x=0;x<2*n+1;x++)
    {
        if(x==0||x==2*n)
        {
            for(y=0;y<n;y++)
                strPtr[x][y]=' ';
            strPtr[x][n]='X';
            strPtr[x][n+1]='\0';
        }
        else if(x==n)
        {
            strPtr[x][0]='X';
            for(y=1;y<2*n;y++)
                strPtr[x][y]=' ';
            strPtr[x][2*n]='X';
            strPtr[x][2*n+1]='\0';
        }
        else if(x<n)
        {
            for(z=0;z<n-x;z++)
                strPtr[x][z]=' ';
            strPtr[x][n-x]='/';
            for(z=n-x+1;z<n+x;z++)
                strPtr[x][z]=' ';
            strPtr[x][n+x]='\\';
            strPtr[x][n+x+1]='\0';
        }
        else if(x>n)
        {
            for(z=0;z<x-n;z++)
                strPtr[x][z]=' ';
            strPtr[x][x-n]='\\';
            for(z=x-n+1;z<2*n-1-q;z++)
                strPtr[x][z]=' ';
            q++;
            strPtr[x][2*n-1-q]='/';
            strPtr[x][2*n-q]='\0';
        }
    }
    return;
}