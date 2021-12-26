/*已知某个学生n门课的成绩,求平均成绩。
输入格式:
共两行，第一行为一个整数n，代表课程数，n不会超过100。第二行为n个用空格分隔的整数，代表该学生的n门课成绩，每门成绩的取值范围是0-100。
要求这n个成绩必须使用数组存储。
输出格式:
只有一行，为该同学的平均成绩，保留两位小数。为了提高精度，求出的平均成绩建议使用double类型存储。*/

#include<stdio.h>
int main()
{
    int n,x;
    scanf("%d",&n);
    int score[n];
    double average=0;
    for(x=0;x<n;x++)
    {
        scanf("%d",&score[x]);
        average+=score[x];
    }
    printf("%.2f",average/n);
    return 0;
}