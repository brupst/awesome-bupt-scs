/*英格兰足球超级联赛（Premier League），通常简称“英超”，是英格兰足球总会属下的最高等级职业足球联赛。
英超联赛采取主客场双循环赛制比赛，每支队伍与各球队对赛两次，主客各一次。由1995/96赛季开始参赛球队由22队减至20队，每支球队共进行38场赛事，
主场和客场比赛各有19场。每场胜方可得3分，平局各得1分，负方得0分，按各队于联赛所得的积分排列。
现请你写一个函数来计算某支球队的当前的积分。
输入：
只有一行，为一个字符串。该字符串包含不多于40个字符，每个字符代表该队一轮比赛的结果。字符串中只包含W（代表该队某轮取胜）、
D（代表该队某轮和对手打平）和L（代表该队某轮失利）三种字符。
输出：
只有一个整数，为根据输入数据，计算出的该队当前的积分。*/

#include <stdio.h>

#define        MAX        48

int        getScore(char * s) ;

int main()
{
    char    input[MAX] ;
    int        score ;

    scanf("%s",input);
    score = getScore(input) ;
    printf("%d\n",score) ;

    return 0;
}

int        getScore(char * s) 
{
    int x,ans=0;
    for(x=0;s[x]!='\0';x++)
    {
        switch(s[x])
        {
            case 'W':ans+=3;break;
            case 'D':ans++;break;
        }
    }
    return ans;
}