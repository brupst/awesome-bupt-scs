/*已知一个英文单词，该单词中只包含大写字母“A—Z”与小写字母“a—z”。你的任务是将英文单词翻译成密码文。
翻译规则是把所有字母用它后面的第三个字母替换，并假设字符a接在字符z后面，字符A接在字符Z后面。例如：zero将被翻译成chur。
输入格式:
只有一样，为一个长度不超过100，只包含英文大小写字母的字符串（以回车换行符‘\n’结尾）。
输出格式:
只有一行，为对应字符串的密码文。*/

#include<stdio.h>
int main()
{
    char letter;
    while(1)
    {
        letter=getchar();
        if(letter=='\n')
            break;
        if(letter>='a'&&letter<'x')
            printf("%c",(letter+3));
        else if(letter>='x'&&letter<='z')
            printf("%c",(letter-23));
        else if(letter>='A'&&letter<'X')
            printf("%c",(letter+3));
        else if(letter>='X'&&letter<='Z')
            printf("%c",(letter-23));
    }
    return 0;
}
