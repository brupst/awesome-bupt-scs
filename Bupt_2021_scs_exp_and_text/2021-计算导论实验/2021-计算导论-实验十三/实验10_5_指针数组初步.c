/*已知一个总长度不超过10000的字符串，字符串中只包含大写字母“A—Z”、小写字母“a—z”和空格‘ ’。空格用于分割单词，空格的个数不超过1000个。
你的任务是将字符串中用空格分隔的单词打印出来。 你要按照如下要求完成任务： 
1.利用指针数组指向每个单词的开始位置。 
2.把字符串中单词结束后的空格改为“\0”,然后使用指针数组将每个单词打印出来。 此题要求用函数完成。*/

#include<stdio.h>

int getString( char * source , char *strPtr[] ) ;

int main()
{
    char    str[100005];
    char    *strPtr[1005]={0};
    int        i, num ;

    gets(str);
    num = getString( str , strPtr ) ;
    for( i = 0 ; i < num ; i++ )
        puts(strPtr[i]);

    return 0;    
}

int getString( char * source , char *strPtr[] ) 
{
    int x,y=0;
    int space=1;
    int word=0;
    int count=0;
    for(x=0;source[x]!='\0';x++)
    {
        if(source[x]!=' '&&space==1&&word==0)
        {
            space=0;
            word=1;
            strPtr[y]=&source[x];
            y++;
            count++;
        }
        else if(space==0&&word==1&&source[x]==' ')
        {
            space=1;
            word=0;
            source[x]='\0';
        }
    }
    return count;
}