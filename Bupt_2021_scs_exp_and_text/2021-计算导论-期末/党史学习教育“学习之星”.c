/*2021年2月1日，为了激励全党不忘初心、牢记使命，在新时代不断加强党的建设，中共中央决定的在全党开展党史学习教育活动。
按照某大学党史学习教育工作安排，现面向全体师生党员开展党史学习教育“学习之星”评选活动。评选条件有很多，
比如认真学习贯彻习近平新时代中国特色社会主义思想和习近平总书记关于党史学习教育的重要论述、重要指示批示和回信精神，带头树牢“四个意识”，坚定“四个自信”，
坚决做到“两个维护”，自觉遵守党章，严格遵守党的各项纪律，认真履行党员义务，正确行使党员权利，在党史学习教育中表现突出。再比如学习的积极性高，
能够坚持学习党的基本理论知识，主动参与党史学习教育活动，及时关注重大时政要闻，积极学习各级各类文件精神等等。
其中有这样三个条件：
1、学习强国年度积分大于等于15000；
2、在历年年度民主评议党员中被评为“优秀”；
3、校级及以上评选中被评为优秀党员。
只要满足其中两个就可以获得加分。现在请你根据这个规则来写一个程序把所有可以获得加分的党员都选出来。
输入： 第一行为一个整数n(0<n<100)，代表党员人数。 后边n行为党员信息，格式为，一个字符串代表党员编号（长度不超过15)，后边为三个用空格分隔的整数，
依次代表学习强国年度积分，是否在历年年度民主评议党员中被评为“优秀”（1代表是，0代表否），是否在校级及以上评选中被评为优秀党员（1代表是，0代表否）。
输出： 若干行（至少一行），每行代表一个符合条件的党员信息（单行的格式与输入一样）。这些党员信息的输出顺序与输入顺序相同。具体见样例。
测试用例保证合法，且至少有一名党员符合条件。
此题需要实现两个函数： 
1、PARTYMEMBER * getMemory(int size) ;
该函数的功能是获取保存党员信息数组的内存。
2、void getAll(PARTYMEMBER * mumbers , int size ) ; 
该函数的功能是找到可以获得加分的党员并输出这些党员的信息。*/

#include<stdio.h>
#include<stdlib.h>

typedef struct partyMember    //保存党员信息的结构 
{
    char    id[16];        //党员编号 
    int        score;        //学习强国年度积分
    int        appraisal;    //是否在历年年度民主评议党员中被评为“优秀” 
    int        isOutstanding;    //是否在校级及以上评选中被评为优秀党员 
} PARTYMEMBER;

void    getAll(PARTYMEMBER * mumbers , int size ) ;
PARTYMEMBER * getMemory(int size) ; 


int main()
{
    int            i , n ;
    PARTYMEMBER    *mumbers ;

    scanf( "%d" , &n ) ;

    mumbers = getMemory(n) ;
    if ( mumbers != NULL )    //如果申请到了内存 
    {
        for( i = 0 ; i < n ; i++ ) /*读入所有党员信息*/
        {
            scanf( "%s%d%d%d" , mumbers[i].id , &mumbers[i].score ,
                    &mumbers[i].appraisal , &mumbers[i].isOutstanding );
        }

        getAll( mumbers , n ) ; 
        free(mumbers) ;//释放内存
    }                        

    return 0;
}

PARTYMEMBER * getMemory(int size) 
{
    PARTYMEMBER *a;
    a=(PARTYMEMBER *)malloc(sizeof(PARTYMEMBER)*(size+1));
    return a;
}

void    getAll(PARTYMEMBER * mumbers , int size ) 
{
    int x;
    int count=0;
    for(x=0;x<size;x++)
    {
        count=0;
        if(mumbers[x].score>=15000)
            count++;
        if(mumbers[x].appraisal)
            count++;
        if(mumbers[x].isOutstanding)
            count++;
        if(count>1)
            printf("%s %d %d %d\n",mumbers[x].id,mumbers[x].score,mumbers[x].appraisal,mumbers[x].isOutstanding);
    }
    return;
}