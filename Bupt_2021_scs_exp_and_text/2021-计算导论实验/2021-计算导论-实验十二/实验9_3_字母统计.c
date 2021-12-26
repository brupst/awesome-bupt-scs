/*任意给定一个字符串，字符串中包含除了空白符、换行符之外的的任意字符。你的任务是统计出现在该字符串中的各字母（即“A—Z”，“a—z”）的个数(区分大小写)。
输入格式:
一个长度不超过100的非空字符串。字符串中不会出现空白符、换行符。
输出格式:
字符串中出现的字母的统计信息，每个字母的统计信息占一行，按照字母的ASCII码的顺序输出。*/

#include<stdio.h>
int main()
{
    int a[256]={0};
    char b[101];
    int x;
    gets(b);
    for(x=0;b[x]!='\0';x++)
        a[(int)b[x]]++;
    for(x=65;x<91;x++)
    {
        if(a[x]!=0)
            printf("The character %c has presented %d times.\n",(char)x,b[x]);
    }
    for(x=97;x<123;x++)
    {
        if(a[x]!=0)
            printf("The character %c has presented %d times.\n",(char)x,b[x]);
    }
    return 0;
}