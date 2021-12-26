/*已知正整数n，n的范围不确定。从键盘读入n个字符串，每个字符串的长度小于1000，要保存到动态数组中。
为了能访问到所有的字符串，需要建立一个长度为n的动态指针数组，用于保存n个字符数组的内存地址。
在读入每个字符串时，用一个长度为1000的字符数组作为缓冲数组，将字符串读入并求出长度后，再动态分配空间，将缓冲数组中的字符串复制到新分配的动态空间中，
并将动态空间的首地址保存到指针数组中。读完n个字符串后你要将这n个字符串按照ASCII码顺序升序排序，然后再打印到屏幕上。
字符串中可能包含大小写字母“A-Z”、“a—z”与空格字符。每个字符串以换行符结束输入。*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sort(char ** a,int n);

int main()
{
    char s[1001];
    int n,k,i,j;
    scanf("%d",&n);
    getchar();
    char **cptr;
    cptr=(char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++)
    {
        gets(s);
        k=strlen(s);
        cptr[i]=(char*)malloc(sizeof(char)*(k+1));
        strcpy(cptr[i],s);
    }
    sort(cptr,n);
    for(i=0;i<n;i++)
    {
        puts(cptr[i]);
        free(cptr[i]);
    }
    free(cptr);
    return 0;
}

void sort(char **a,int n)
{
    int x,y;
    char *temp;
    for(x=0;x<n;x++)
    {
        for(y=0;y<n-1;y++)
        {
            if(strcmp(a[y],a[y+1])>0)
            {
                temp=a[y+1];
                a[y+1]=a[y];
                a[y]=temp;
            }
        }
    }
}