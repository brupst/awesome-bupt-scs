/*设计函数int getVowel(char str[],char vowel[])，将只包含小写字母的字符串str中的元音字母“a”“e”“i”“o”“u”复制到字符数组vowel，
并返回字符串vowel的长度。*/

#include <stdio.h>
#include<stdio.h>

//将只包含小写字母的字符串str中的元音字母复制到字符数组vowel,并返回元音字符的个数。
int getVowel(char str[],char vowel[]);

int main()
{
    char    vowel[101] , str[101];//每个数组都至少要101个字节 
    int        len ;

    scanf("%s",str);    //读入字符串 
    len = getVowel(str,vowel);    //复制 
    if ( len > 0 ) printf("%d %s\n", len , vowel);    //输出复制后结果 
    else printf("%d\n", len);//仅输出长度 

    return 0;    
}

int getVowel(char str[],char vowel[])
{
    int x,count=0,y=0;
    for(x=0;str[x]!='\0';x++)
    {
        if(str[x]=='a'||str[x]=='e'||str[x]=='i'||str[x]=='o'||str[x]=='u')
        {
            vowel[y]=str[x];
            count++;
            y++;
        }
    }
    vowel[y]='\0';
    return count;
}