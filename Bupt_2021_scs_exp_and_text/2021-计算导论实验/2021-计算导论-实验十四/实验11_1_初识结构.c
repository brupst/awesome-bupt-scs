/*学生的属性包括姓名、学号、5门课程的成绩、平均成绩与总成绩。已知一个学生的姓名、学号与5门课程的成绩，你的任务是计算该学生的平均成绩与总成绩，
并将该学生的5门课程成绩按照从高到底进行排序，最后将这个同学的完整信息输出。学生的姓名中只能包含大小写字母与空格字符，不会超过20个字符；
学生的学号是个长度不会超过20的字符串，只包含数字字符；课程成绩均为0—100的整数。
要求：
1.在本题中，你要设计一个结构来存储学生的信息。在此结构中，需要有一个字符数组来存储姓名；一个字符数组来存储学号；
一个长度为5的整型数组来存储5门课程的成绩；一个双精度浮点型变量存储平均成绩，一个整型变量存储总成绩。
2.在对结构变量的成员进行赋值与排序的时候，你要使用“结构变量名+‘.’+结构成员名”这种方式访问变量，如“student.score”；
而在输出学生信息时，你要用一个结构指针指向该结构，然后用结构指针访问结构中的变量，即“结构指针名+‘->’+结构成员名”，如“ptr->score”。
输入格式:
学生信息的输入按照姓名、学号、5门课程成绩的顺序输入，共占三行，具体格式见样例。
输出格式:
姓名占一行；学号占一行；5门成绩中间用空格分开，最后一个成绩后是换行符，从高到底进行排序，占一行；平均成绩与总成绩用空格分隔，
占一行，平均成绩保留两位小数。*/

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
void b_sort(Student *a);

int main()
{
    Student a;
    int x;
    gets(a.name);
    gets(a.id);
    for(x=0;x<5;x++)
        scanf("%d",&a.score[x]);
    b_sort(&a);
    print(&a);
    return 0;
}

void b_sort(Student *a)
{
    int x,y,temp;
    for(x=0;x<5;x++)
    {
        for(y=0;y<4;y++)
        {
            if(a->score[y]<a->score[y+1])
            {
                temp=a->score[y];
                a->score[y]=a->score[y+1];
                a->score[y+1]=temp;
            }
        }
    }
    return;
}

void print(Student *a)
{
    a->total=a->score[0]+a->score[1]+a->score[2]+a->score[3]+a->score[4];
    a->average=(float)(a->total)/5;
    printf("Name:%s\n",a->name);
    printf("ID:%s\n",a->id);
    printf("Score:%d %d %d %d %d\n",a->score[0],a->score[1],a->score[2],a->score[3],a->score[4]);
    printf("average:%.2f total:%d",a->average,a->total);
    return;
}