/*有n名学生，每个学生的属性包括姓名与总成绩。已知学生的姓名与总成绩，你的任务是将学生的信息按照以下方式排序：首先比较总成绩，总成绩高的在前面，
总成绩低的在后面，当总成绩相同时，你要比较学生的姓名，姓名字典序小的同学在前面，姓名字典序大的同学在后面(ASCII码顺序)。n的范围是1—100；
学生的姓名中只能包含大小写字母，不会超过20个字符；总成绩为整数。
要求：在本题中，你要设计一个结构来存储学生的信息。在此结构中，需要有一个字符数组来存储姓名，一个整型变量存储总成绩。
输入格式:
首先输入一个正整数n，代表学生的数量，1<=n<=100；每名学生的信息按照姓名、总成绩的顺序输入（空格分开），每名学生信息占一行。具体格式见样例。
输出格式:
n名学生的信息，姓名占一行，总成绩占一行，输出顺序要按照题目的要求，每名同学的信息后都再输出一个空行。 注意：每名同学的信息后都再输出一个空行。*/

#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[50];
    int total;
}Student;

void sort(Student a[],int n);

int main()
{
    int n,i,j;
    scanf("%d",&n);
    Student a[110];
    for(i=0;i<n;i++)
    {
        getchar();
        scanf("%s %d",a[i].name,&a[i].total);
    }
    sort(a,n);
    for(i=0;i<n;i++)
    {
        printf("Name:%s\n",a[i].name);
        printf("total:%d\n\n",a[i].total);
    }
    return 0;
}

void sort(Student a[],int n)
{
    int x,y;
    Student q;
    for(x=1;x<n;x++)
    {
        for(y=0;y<n-x;y++)
        {
            if(a[y].total<a[y+1].total)
            {
                q=a[y];
                a[y]=a[y+1];
                a[y+1]=q;
            }
            else if(a[y].total==a[y+1].total)
            {
                if(strcmp(a[y].name,a[y+1].name)>0)
                {
                    q=a[y];
                    a[y]=a[y+1];
                    a[y+1]=q;
                }
            }
        }
    }
    return;
}