/*已知正整数n，n的范围是1—100。你要从键盘读入n个字符串，每个字符串的长度不确定，但是n个字符串的总长度不超过100000。
你要利用字符指针数组将这n个字符串按照ASCII码顺序进行升序排序，然后再打印到屏幕上。字符串中可能包含ASCII码中的任意字符，每个字符串以换行符结束输入。
要求：不允许定义如char str[100][100000];这样的二维数组，因为会极大的浪费内存空间。你应定义char str[100000];这样的存储空间，
将n个字符串连续的存储在一维字符空间内，然后将这n个字符串的起始位置保存在字符指针数组中，再进行排序操作。
输入格式:
输入一个正整数n，代表待排序字符串的个数，n不超过100，然后是n个字符串，每个字符串的长度不确定，但至少包含1个字符。n个字符串的总长度不会超过100000。
输出格式:
排序后的n个字符串，每个字符串占一行。*/

#include<stdio.h>
#include<string.h>

void sort(char *a[],int n);

int main()
{
    char str[100001];
    int n,x,k=1;
    scanf("%d",&n);
    getchar();
    char *ptr[n];
    ptr[0]=str;
    for(x=0;x<100001;x++)
    {
        str[x]=getchar();
        if(str[x]=='\n')
        {
            str[x]='\0';
            ptr[k]=&str[x+1];
            k++;
        }
    }
    sort(ptr,n);
    for(x=0;x<n;x++)
        puts(ptr[x]);
    return 0;
}

void sort(char *a[],int n)
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