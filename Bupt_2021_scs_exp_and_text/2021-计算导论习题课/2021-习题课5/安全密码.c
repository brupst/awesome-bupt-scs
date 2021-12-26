/*某网站规定注册账号时密码必须达到一定强度才可以。他们规定密码长度至少6位，数字、大写字母、小写字母、符号（~!@#$%^&*()[]}{|<>?/.,:"';）
这四类中至少包含三类才合格。现在请你写一段程序来判断一个密码是否合格。
输入格式:
第一行为一个整数n(0<n<10),代表测试用例组数， 后边是n行测试用例，每行为一个长度不超过30的字符串。
输出格式:
共n行，与输入的n行测试用例相对应，如果密码合格则输出yes，否则输出no。*/

#include<stdio.h>
#include<string.h>

int judge(char * a);

int main()
{
    int n,x;
    char a[31];
    scanf("%d",&n);
    getchar();
    for(x=0;x<n;x++)
    {
        gets(a);
        if(judge(a))
            puts("yes");
        else
            puts("no");
    }
    return 0;
}

int judge(char * a)
{
    int x;
    int e=0,b=0,c=0,d=0;
    int count=0;
    if(strlen(a)<6)
        return 0;
    for(x=0;a[x]!='\0';x++)
    {
        if(a[x]>='A'&&a[x]<='Z')
            e++;
        else if(a[x]>='0'&&a[x]<='9')
            b++;
        else if(a[x]>='a'&&a[x]<='z')
            c++;
        else
            d++;
    }
    if(e>0)
        count++;
    if(b>0)
        count++;
    if(c>0)
        count++;
    if(d>0)
        count++;
    if(count>2)
        return 1;
    else
        return 0;
}