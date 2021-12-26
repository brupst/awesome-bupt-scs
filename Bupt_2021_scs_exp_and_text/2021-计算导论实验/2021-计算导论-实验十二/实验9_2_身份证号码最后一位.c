/*身份证编码规则如下：根据〖中华人民共和国国家标准GB11643-1999〗中有关公民身份号码的规定，
公民身份号码是特征组合码，由十七位数字本体码和一位数字校验码组成。
计算方法
1、将前面的身份证号码17位数分别乘以不同的系数。从第一位到第十七位的系数分别为：7－9－10－5－8－4－2－1－6－3－7－9－10－5－8－4－2。
2、将这17位数字和系数相乘的结果相加。
3、用加出来和除以11，看余数是多少？
4、余数只可能有0－1－2－3－4－5－6－7－8－9－10这11个数字。其分别对应的最后一位身份证的号码为1－0－X －9－8－7－6－5－4－3－2。
（即余数0对应1，余数1对应0，余数2对应X...）
5、通过上面得知如果余数是3，就会在身份证的第18位数字上出现的是9。如果对应的数字是2，身份证的最后一位号码就是罗马数字X。
现在请你写一段程序来判断一个身份证号码的最后一位是否与上述规则相符。
输入格式:
第一行一个整数T(0<T<100)，表示有T行测试数据。后边是T行每行是一个18位的身份证号码
（测试数据前17位保证符合身份证号码的要求，罗马数字X就是大写的英文字母X）。
输出格式:
T行，与输入的T行测试数据相对应，如果该行测试数据最后一位符合所述算法则输出right，否则输出wrong。*/

#include<stdio.h>
#include<string.h>

void trans(char id[],int id_pre17[]);
int judge(char id[],int id_pre17[]);

int main()
{
    int n,x,y;
    int judgement=0;
    scanf("%d",&n);
    char id[19];
    char id2[19];
    int id_pre17[17];
    for(x=0;x<n;x++)
    {
        scanf("%s",id);
        strcpy(id2,id);
        trans(id2,id_pre17);
        if(judge(id,id_pre17))
            puts("right");
        else
            puts("wrong");
    }
    return 0;
}

void trans(char id[],int id_pre17[])
{
    int x;
    for(x=0;x<17;x++)
        id_pre17[x]=(id[x]-'0');
    return;
}

int judge(char id[],int id_pre17[])
{
    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char judge[12]={'1','0','X','9','8','7','6','5','4','3','2'};
    int number=0,x;
    for(x=0;x<17;x++)
        number+=(weight[x]*id_pre17[x]);
    number%=11;
    if(id[17]==judge[number])
        return 1;
    else
        return 0;
}