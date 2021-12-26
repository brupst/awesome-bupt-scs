/*设计函数 void delcharfun(char *str,char ch)实现从字符串str中删除指定的字符ch。同一字母的大、小写按不同字符处理。*/

#include<stdio.h>

void delcharfun(char *str,char ch);

int main()
{
    char    ch,str[110];

    scanf("%s",str);    //读入字符串 
    getchar();            //读取回车符号 
    scanf("%c",&ch);    //读入字符 
    delcharfun(str,ch);    //删除 
    printf("%s\n",str);    //输出删除后结果 
    return 0;    
}

void delcharfun(char *str,char ch)
{
    int x,y,k;
    for(x=0;str[x]!='\0';x++)
    {
        if(str[x]==ch)
        {
            k=x;
            for(y=x;str[y]!='\0';y++)
                str[y]=str[y+1];
            x=k-1;
        }
    }
    return;
}