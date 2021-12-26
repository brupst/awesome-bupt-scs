/*简单字符处理，不允许使用数组。
输入格式:
为一个以换行符”\n”结尾的字符串，字符串长度大于0且小于200。
输出格式:
第一行为将该字符串中的小写字母替换为大写字母后的字符串。
第二行为一个整数，为该字符串中所有元音字母的个数。*/

#include<stdio.h>
int main()
{
    char letter;
    int count=0;
    while(1)
    {
        scanf("%c",&letter);
        if(letter=='\n')
            break;
        if(letter=='a'||letter=='A'||letter=='e'||letter=='E'||letter=='i'||letter=='I'||letter=='o'||letter=='O'||letter=='u'||letter=='U')
            count++;
        if(letter>='a'&&letter<='z')
            printf("%c",(letter-32));
        else
            printf("%c",letter);
    }
    printf("\n%d",count);
    return 0;
}