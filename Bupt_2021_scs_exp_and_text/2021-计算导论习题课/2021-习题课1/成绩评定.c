/*某大学研究生学位论文答辩成绩的计算方法规定： 
1、答辩总成绩为参加答辩全体委员评分的总和除以评分人数。 
2、每个参加答辩的委员给的评分范围是40到100分。
3、平均后的成绩为90分以上时，成绩记为A，成绩小于等于90分且大于70分时，成绩记为B，成绩小于等于70分且大于50分时，
成绩记为C，成绩小于等于50分时，成绩记为D。 
现在请你写一段程序来计算某位同学的得分。
输入格式:
只有一行，为7个用空格分隔的整数。代表全部7位答辩委员的评分。
输出格式:
只有一行，格式为先输出成绩等级（即A、B、C或D），然后输出冒号，最后输出答辩总成绩（保留一位小数）。
测试用例保证输入合法，浮点数建议采用float类型。*/

#include<stdio.h>
int main()
{
    float score,last_score;
    float sum=0;
    float p=1;
    while(scanf("%f",&score)==1)
    {
        sum+=score;
        last_score=sum/7;
    }
    if(last_score>90)
    {    
        printf("A:");
    }
    else if(70<last_score&&last_score<=90)
    {
        printf("B:");
    }
    else if(50<last_score&&last_score<=70)
    {
        printf("C:");
    }
    else
    {
        printf("D:");
    }
    printf("%.1f",last_score);
    return 0;
}