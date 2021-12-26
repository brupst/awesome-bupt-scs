/*用’-‘(减号)、’+’(加号)、’|’(竖线)、’*’星号和空格打印方格。
输入格式:
只有一行，为用空格分隔的两个整数l,c（0<l,c<10）。其中l和c分别代表格子的行数和列数。请看输入样例。
输出格式:
每组测试用例输出一组（请看输出样例）。*/

#include<stdio.h>
int main()
{
    int m,n,c,l;
    scanf("%d%d",&l,&c);
    for(m=0;m<l;m++)
    {
        for(n=0;n<c;n++)
        {
            printf("|*****");
        }
        printf("|\n");
        for(n=0;n<c;n++)
        {
            printf("|  |  ");
        }
        printf("|\n");
        for(n=0;n<c;n++)
        {
            printf("|--+--");
        }
        printf("|\n");
        for(n=0;n<c;n++)
        {
            printf("|  |  ");
        }
        printf("|\n");   
    }
    for(n=0;n<c;n++)
    {
        printf("|*****");
    }
    printf("|\n");
    return 0;
}