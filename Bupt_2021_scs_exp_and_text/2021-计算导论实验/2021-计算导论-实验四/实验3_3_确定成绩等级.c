/*���ٷ��Ƴɼ�score������ԭ�򻮷���ȼ���
score��90�ȼ�ΪA��
80 ��score<90���ȼ�ΪB��
70��score<80���ȼ�ΪC��
60��score<70,�ȼ�ΪD��
score<60,�ȼ�ΪE��
�����ʽ:
ֻ��һ������������ɼ�score������������֤��������������int�洢��
�����ʽ:
ֻ��һ�У����ɼ�С��0�����100ʱΪ"The score is out of range!"�����������ţ�������Ϊ�����ѧ���ɼ���Ӧ�ĵȼ���*/

#include<stdio.h>
int main()
{
    int score;
    scanf("%d",&score);
    if(score>=90&&score<=100)
    {
        printf("A");
    }
    else if(80<=score&&score<90)
    {
        printf("B");
    }
    else if(70<=score&&score<80)
    {
        printf("C");
    }
    else if(60<=score&&score<70)
    {
        printf("D");
    }
    else if(score<60&&score>=0)
    {
        printf("E");
    }
    else if(score<0||score>100)
    {
        printf("The score is out of range!");
    }
    return 0;
}