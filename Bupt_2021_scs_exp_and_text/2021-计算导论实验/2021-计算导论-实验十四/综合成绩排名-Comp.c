/*众所周知，计算机院要对申请转入计算机大类的学生进行考核，考核方式包括机试和面试。学生综合成绩采取百分制，其中50%由机试成绩核算，
另50%由学生已获得的加权成绩核算。综合成绩优秀者可进入面试环节。现请你写一个根据学生成绩来确定综合成绩排名的程序。
输入： 第一行为一个整数n(0<n<100)，代表学生人数。 后边n行为学生信息，格式为，一个字符串代表学生学号（长度不超过15)，后边为两个整数，
前边的代表机试成绩，后一个代表学生已获得的加权成绩。（两类成绩均在0到100之间）。
输出： 共n行，按综合成绩（机试成绩加加权成绩）从高到低每行输出每个学生的信息，如果综合成绩相同，则机试成绩高的学生在前。每行的格式为：
一个字符串（学生学号）加三个整数(4个数据之间均用一个空格分隔)，这三个整数依次为综合成绩，机试成绩和加权成绩，
测试用例保证输入合法且不存在成绩完全相同的学生。
程序中用的结构体定义及各成员含义如下：
程序中用到3个函数，分别为：
void Swap(STUDENT * s1,STUDENT * s2) ;
其中参数s1,s2为指向两个结构体的指针，其功能是将这两个指针指向的结构体内的值互相交换。
int Comp(STUDENT * s1,STUDENT * s2) ;
其中参数s1,s2为指向两个结构体的指针，其功能是比较两个结构体， 如果s1>s2则返回1，否则返回0。这里s1>s2指的是s1的总分高，
或者总分相同时指的是s1的机试成绩高。测试用例保证输入合法且不存在成绩完全相同的学生。
void Sort(STUDENT a[],int size) ;
其中参数a为待排序的结构体数组，size为数组中学生的数量。其功能是将a按题目指定规则排序。*/

#include <stdio.h>

typedef struct
{
    char    id[16]  ;//学生账号 
    int        total ;    //综合成绩 
    int        ce ;    //机试成绩 
    int        ws ;    //加权成绩 
}STUDENT;

void Sort(STUDENT a[],int size) ; 
void Swap(STUDENT * s1,STUDENT * s2) ;
int  Comp(STUDENT * s1,STUDENT * s2) ;

int main()
{
    STUDENT    stu[100] ;
    int        i , n ;


    scanf("%d",&n) ;
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d",stu[i].id,&stu[i].ce,&stu[i].ws) ;
        stu[i].total = stu[i].ce+stu[i].ws ;
    }

    Sort(stu,n) ;
    for(i=0;i<n;i++)
        printf("%s %d %d %d\n",stu[i].id,stu[i].total,stu[i].ce,stu[i].ws) ;

    return 0;    
}

/* 请在这里填写答案 */