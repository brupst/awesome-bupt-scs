/*大家都知道在电商网站上买东西时，网站会根据我们的搜索条件给出非常多的商品。
这些商品会以依据某一种排序规则进行排序，依次呈现在我们面前。现在某电商网站关于书籍的排序依据有这么几项，综合、销量、出版时间、价格、用户评分。
假设综合排名的规则为：首先看价格，价格低的排名靠前，如果价格相同，则看出版时间，出版的晚的排名靠前，如果这两项都相同则看销量，销量大的靠前，
如果前三项均相同，最后看用户评分，用户评分高的排名靠前。
请依据此规则写一段给各个书按综合排名的程序。
输入格式:
第一行为一个整数n(1<n<100),后面是n行书籍的数据，共7列，每列之间以空格分隔。其中第一列为书名（长度小于60且仅包含大写字母和小写字母的字符串），
第二列到第七列均为大于等于0的整数，分别代表该书的销量、出版时间的年、月、日、价格和用户评分。
输出格式:
n行，每行输出一本书的信息，与输入时格式一致（测试数据中保证没有排名一样的书籍，且所有整数均可以用int存储）。*/

#include<stdio.h>

typedef struct 
{
    char name[100];
    int sale;
    int year;
    int month;
    int day;
    int price;
    int score;
}BOOK;

int Comp(BOOK a,BOOK b);
void Exchange(BOOK *a,BOOK *b);
void Sort(BOOK a[],int n);

int main()
{
    int n,x;
    scanf("%d",&n);
    BOOK library[n];
    for(x=0;x<n;x++)
        scanf("%s %d %d %d %d %d %d",library[x].name,&library[x].sale,&library[x].year,&library[x].month,&library[x].day,&library[x].price,&library[x].score);
    Sort(library ,n);
    for(x=0;x<n;x++)
        printf("%s %d %d %d %d %d %d\n",library[x].name,library[x].sale,library[x].year,library[x].month,library[x].day,library[x].price,library[x].score);
    return 0;
}

int Comp(BOOK a,BOOK b)
{
    if(a.price<b.price)
        return 1;
    else if(a.price>b.price)
        return 0;
    else
    {
        if(a.year>b.year)
            return 1;
        else if(a.year<b.year)
            return 0;
        else
        {
            if(a.month>b.month)
                return 1;
            else if(a.month<b.month)
                return 0;
            else
            {
                if(a.day>b.day)
                    return 1;
                else if(a.day<b.day)
                    return 0;
                else
                {
                    if(a.sale>b.sale)
                        return 1;
                    else if(a.sale<b.sale)
                        return 0;
                    else
                    {
                        if(a.score>b.score)
                            return 1;
                        else
                            return 0;
                    }
                }
            }
        }
    }
}

void Exchange(BOOK *a,BOOK *b)
{
    BOOK temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return;
}

void Sort(BOOK a[],int n)
{
    int x,y;
    for(x=0;x<n;x++)
    {
        for(y=x+1;y<n;y++)
        {
            if(!Comp(a[x],a[y]))
                Exchange(&a[x],&a[y]);
        }
    }
    return;
}