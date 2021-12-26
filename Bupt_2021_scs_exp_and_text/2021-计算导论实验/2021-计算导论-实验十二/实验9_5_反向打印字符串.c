/*设计递归函数将字符串str中的内容反向打印出来。*/

#include<stdio.h>

//将字符串str中的内容反向打印的函数 
void reversePrint(char str[]) ;

int main()
{
    char    s[100] ;

    scanf( "%s" , s );    
    reversePrint(s) ;
    printf("\n") ;

    return 0;
}

void print(char * str,int x);

void reversePrint(char str[]) 
{
    int x=strlen(str);
    print(str,x);
}

void print(char * str,int x)
{
    if(x==0)
        return;
    else if(x>0)
    {
        printf("%c",str[x-1]);
        print(str,x-1);
        return;
    }
}