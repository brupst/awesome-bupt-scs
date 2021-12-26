/*将百分制成绩score按下列原则划分其等级：
score≥90等级为A；
80 ≤score<90，等级为B；
70≤score<80，等级为C；
60≤score<70,等级为D；
score<60,等级为E。
输入格式:
只有一个整数，代表成绩score。测试用例保证所有整数可以用int存储。
输出格式:
只有一行，当成绩小于0或大于100时为"The score is out of range!"（不包括引号），否则为输入的学生成绩对应的等级。*/

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