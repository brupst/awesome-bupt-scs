/*给定一行字符，分别统计出其中英文字母、空格、数字和其他字符的个数。
输入格式:
只有一行，为一个字符序列，字符序列长度小于100，以回车键结束。
输出格式:
只有一行，为4个用空格分隔的整数，依次代表输入字符序列中英文字符，空格，数字以及其他字符的数量。*/

#include<stdio.h>
int main()
{
  int character,space,number,others;
  character=space=others=number=0;
  char input;
  while((input=getchar())!='\n')
  {
    if(input>='A'&&input<='Z'||input>='a'&&input<='z')
    {
      character++;
    }
    else if(input==' ')
    {
      space++;
    }
    else if('0'<=input&&input<='9')
    {
      number++;
    }
    else
    {
      others++;
    }
  }
  printf("%d %d %d %d",character,space,number,others);
  return 0;
}