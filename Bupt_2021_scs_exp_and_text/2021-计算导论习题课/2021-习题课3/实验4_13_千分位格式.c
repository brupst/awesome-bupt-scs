/*已知一个整数n，你要将它输出成“千分位”形式。即从个位数起，每3位之间加一个逗号。例如，将“7654321”写成“7,654,321”。
输入格式:
只有一个整数n（0<=n<2000000000）。
输出格式:
只有一行，为输入的n的“千分位”输出形式。*/

#include<stdio.h>
int main()
{
    char number[100];
    int x,y,temp;
    scanf("%s",number);
    for(x=0;number[x]!='\0';x++);
    temp=x%3;
    for(y=0;y<x;y++)
    {
        if((y+4-temp)%3==0)
        {
            if(y==x-1)
                printf("%c",number[y]);
            else
                printf("%c,",number[y]);
        }
        else
            printf("%c",number[y]);
    }
    return 0;
}