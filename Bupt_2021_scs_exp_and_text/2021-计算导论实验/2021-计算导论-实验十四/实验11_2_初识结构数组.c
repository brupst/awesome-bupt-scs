/*有n名学生，每个学生的信息包括姓名、学号、5门课程的成绩，平均成绩与总成绩。已知学生的姓名、学号与5门课程的成绩，
你的任务是计算每个学生的平均成绩与总成绩，并将它们输出。学生的姓名中只能包含大小写字母与空格字符，不会超过20个字符；
学生的学号是个长度不会超过20的字符串，只包含数字字符；课程成绩均为0—100的整数。
要求：在本题中，你要设计一个结构来存储一个学生的信息。在此结构中，需要有一个字符数组来存储姓名；一个字符数组来存储学号；
一个长度为5的整型数组来存储5门课程的成绩；一个双精度浮点型变量存储平均成绩，一个整型变量存储总成绩。然后，你要设计一个结构数组来存储n名学生的信息。
输入格式:
输入首先是一个正整数n，代表学生的数量，1<=n<=100；每名学生的信息按照姓名、学号、5门课程成绩的顺序输入，共占三行。输入具体格式见样例。
输出格式:
姓名占一行；学号占一行；5门课程成绩中间用空格分开，最后一个成绩后是换行符，占一行；平均与总成绩用空格分隔，占一行，平均成绩保留两位小数；
每名同学的信息后都再输出一个空行。 注意：每名同学的信息后都再输出一个空行。*/

#include<stdio.h>
typedef struct
{
    char name[21];
    char id[21];
    int score[5];
    double average;
    int total;
}Student;

void print(Student *a);

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    Student a;
    int x,y;
    for(y=0;y<n;y++)
    {
        gets(a.name);
        gets(a.id);
        for(x=0;x<5;x++)
            scanf("%d",&a.score[x]);
        print(&a);
        getchar();
    }
    return 0;
}

void print(Student *a)
{
    a->total=a->score[0]+a->score[1]+a->score[2]+a->score[3]+a->score[4];
    a->average=(float)(a->total)/5;
    printf("Name:%s\n",a->name);
    printf("ID:%s\n",a->id);
    printf("Score:%d %d %d %d %d\n",a->score[0],a->score[1],a->score[2],a->score[3],a->score[4]);
    printf("average:%.2f total:%d\n",a->average,a->total);
    printf("\n");
    return;
}