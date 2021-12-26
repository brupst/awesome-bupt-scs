/*创建学生信息管理系统，具体要求如下：
学生信息包括：学号 姓名 数学成绩 英语成绩 计算机成绩
功能1：添加学生信息 执行1时，输入学号，姓名，三门科目成绩；如果添加学生成功则输出“Add success”，如果学生已存在则输出“Students already exist”
功能2：删除学生信息 执行2时，输入学号信息；如果学生不存在，输出“Students do not exist”，如果存在，则输出“Delete success”
功能3：更改学生成绩信息 执行3时，输入学号信息；如果学生不存在，输出“Students do not exist”，如果存在，输出“Update success”
功能4：显示学生平均分成绩 执行4时，输入学号信息；如果学生不存在，输出“Students do not exist”，如果存在，则输出学生信息，如下格式：
Student ID:2019989890
Name:Jerry
Average Score:89.3
其中平均分为三门科目相加除以3，保留一位小数，每行之间换行。
输入格式:
第一行为一个整数n(0<n<130)，后边共n行，每一行表示执行一种功能。其中1，2，3，4分别对应执行上面4种功能，具体格式见输入样例。 
测试用例保证：学号和名字均为长度不超过10的字符串，各门课成绩为0到100之间的整数。*/

#include<stdio.h>
#include<string.h>

typedef struct
{
    char id[21];
    char name[21];
    int score[3];
}Student;

int main()
{
    int n,x,y,z,command;
    int a=0;           //统计学生个数
    int judge=0;       //判断学号是否已经存在
    char id_j[21];
    float average=0;
    Student st[140];
    Student temp;
    scanf("%d",&n);
    for(x=0;x<n;x++)
    {
        judge=0;
        average=0;
        getchar();
        scanf("%d",&command);
        if(command==1)
        {
            scanf("%s %s",st[a].id,st[a].name);
            for(y=0;y<3;y++)
                scanf("%d",&st[a].score[y]);
            for(y=0;y<a;y++)
            {
                if(strcmp(st[a].id,st[y].id)==0)
                {
                    judge=1;
                    break;
                }
            }
            if(judge)
                puts("Students already exist");
            else
            {
                a++;
                puts("Add success");
            }
        }
////////////////////////////////////////////////////////////
        else if (command==2)
        {
            scanf("%s",id_j);
            for(y=0;y<a;y++)
            {
                if(strcmp(id_j,st[y].id)==0)
                {
                    judge=1;
                    break;
                }
            }
            if(judge)
            {
                strcpy(st[y].id,"q");
                puts("Delete success");
            }
            else
                puts("Students do not exist");
        }
////////////////////////////////////////////////////////////
        else if (command==3)
        {
            scanf("%s",temp.id);
            for(y=0;y<3;y++)
                scanf("%d",&temp.score[y]);
            for(y=0;y<a;y++)
            {
                if(strcmp(temp.id,st[y].id)==0)
                {
                    judge=1;
                    break;
                }
            }
            if(judge)
            {
                strcpy(temp.name,st[y].name);
                st[y]=temp;
                puts("Update success");
            }
            else
                puts("Students do not exist");
        }
//////////////////////////////////////////////////////////////
        else if (command==4)
        {
            scanf("%s",id_j);
            for(y=0;y<a;y++)
            {
                if(strcmp(id_j,st[y].id)==0)
                {
                    judge=1;
                    break;
                }
            }
            if(judge)
            {
                printf("Student ID:%s\n",st[y].id);
                printf("Name:%s\n",st[y].name);
                for(z=0;z<3;z++)
                    average+=st[y].score[z];
                average/=3;
                printf("Average Score:%.1f\n",average);
            }
            else
                puts("Students do not exist");
        }
    }
    return 0;
}