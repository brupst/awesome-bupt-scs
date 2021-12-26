/*任意给定一个字符串，字符串中包含除了空白符、换行符之外的任意字符。你的任务是检测字符串中的圆括号是否配对，
即“(”与“)”是否配对。如字符串“(（a+b）* (c+d))”中是配对的，而“((a+b)*) c+d))”则不配对。
输入格式:
一个长度不超过100的非空字符串，该字符串中不会出现空格、换行符。
输出格式:
匹配及不匹配见样例。*/

#include<stdio.h>
int main()
{
    char a[101];
    int l=0;
    int x;
    int judge=0;
    gets(a);
    for(x=0;a[x]!='\0';x++)
    {
        if(a[x]=='(')
            l++;
        else if(a[x]==')')
            l--;
        if(l<0)
            judge=1;
    }
    if(l==0&&judge==0)
        puts("parentheses match!");
    else
        puts("parentheses do not match!");
    return 0;
}