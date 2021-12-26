/*现有一个长度不超过100的字符串，该字符串只包含ascii可视字符。请写一段程序将其中的大写字母全部转换为对应的小写字母，小写字母全部转换为对应的大写字母。
输入格式:
只有一行以回车换行符‘\n’结尾的字符串，为待处理字符串。测试用例保证输入合法。
输出格式:
也只有一行，为转换后的对应字符串。*/

#include<stdio.h>
int main()
{
    char word;
    while(1)
    {
        word=getchar();
        if(word=='\n')
            break;
        else
        {
            if('a'<=word&&word<='z')
            {
                printf("%c",(word-32));
            }
            else if('A'<=word&&word<='Z')
                printf("%c",(word+32));
            else
                printf("%c",word);
        }
    }
    return 0;
}