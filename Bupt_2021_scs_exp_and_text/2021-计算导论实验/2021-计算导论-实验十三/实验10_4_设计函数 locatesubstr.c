/*设计函数 char *locatesubstr(char *str1,char *str2)，查找str2指向的字符串在str1指向的字符串中首次出现的位置，返回指向该位置的指针。
若str2指向的字符串不包含在str1指向的字符串中，则返回空指针NULL。 注意这里必须使用指针而不是数组下标来访问字符串。*/

#include <stdio.h>

char *locatesubstr(char *str1,char *str2);
int main()
{
    char str1[505],str2[505];
    char *p;
    gets(str1);
    gets(str2);
    p=locatesubstr(str1,str2);

    if(p==NULL)    printf("NULL!\n");
    else    puts(p);

    return 0;
}

char *locatesubstr(char *str1,char *str2)
{
    int k,x,y,q=0;
    char *ans;
    for(k=0;str2[k]!='\0';k++);
    for(x=0;str1[x]!='\0';x++)
    {
        q=0;
        if(str1[x]==str2[0])
        {
            for(y=1;y<k;y++)
            {
                if(str1[x+y]==str2[y])
                    q++;
                else
                    break;
            }
            if(q==k-1)
            {
                ans=&str1[x];
                return ans;
            }
        }
    }
    ans=NULL;
    return ans;
}