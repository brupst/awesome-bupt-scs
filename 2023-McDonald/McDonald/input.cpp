#include <iostream>
#include "Data_Structure.h"
#include "input.h"
#include "work.h"
#include <cstring>
#include <QtDebug>
int food_id_find(struct Node1 *food_array,char *food_name,int foodnum)
{
    int ans;
    int flag=0;
    for(ans=0;ans<foodnum;ans++)
    {
        if(!strcmp(food_array[ans].food_name,food_name))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        return ans;
    else
    {
        return -1;
    }
}
int combo_id_find(struct Node2 *combo_array,char *combo_name)
{
    int ans;
    int flag=0;
    for(ans=0;ans<combo_kinds_num;ans++)
    {
        if(!strcmp(combo_array[ans].combo_name,combo_name))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        return ans;
    else
        return -1;
}
void combo_food_list_insert(char *food_name,List_combo_food L,combo_food_Position P,struct Node1 *food_array,int foodnum)
{
    combo_food_Position TmpCell;
    TmpCell=(combo_food_Position)malloc(sizeof(Node3));
    TmpCell->id=food_id_find(food_array, food_name,foodnum);
    TmpCell->next=P->next;
    P->next=TmpCell;
}
void Delete_combo_food_list(List_combo_food L)
{
    combo_food_Position P,TmpCell;
    P=L->next;
    L->next=NULL;
    while(P!=NULL)
    {
        TmpCell=P->next;
        free(P);
        P=TmpCell;
    }
}
List_combo_food MakeEmpty_combo_food_list(List_combo_food L)
{
    if(L!=NULL)
        Delete_combo_food_list(L);
    L=(combo_food_Position)malloc(sizeof(Node3));
    L->next=NULL;
    return L;
}
void order_list_insert(List_order L,int order_time,order_Position P,List_order_food L_order_food)
{
    order_Position TmpCell;
    TmpCell=(order_Position)malloc(sizeof(Node4));
    TmpCell->time=order_time;
    TmpCell->order_food_list=L_order_food;
    TmpCell->finish_flag=0;
    TmpCell->receive_flag=0;
    TmpCell->next=P->next;
    P->next=TmpCell;
}
void Delete_order_list(List_order L)
{
    order_Position P,TmpCell;
    P=L->next;
    L->next=NULL;
    while(P!=NULL)
    {
        TmpCell=P->next;
        free(P);
        P=TmpCell;
    }
}
List_order MakeEmpty_order_list(List_order L)
{
    if (L!=NULL)
        Delete_order_list(L);
    L=(order_Position)malloc(sizeof(Node4));
    L->next=NULL;
    return L;
}
void order_food_list_insert(List_order_food L,int insert_id,order_food_Position P)
{
    order_food_Position TmpCell;
    TmpCell=(order_food_Position)malloc(sizeof(Node5));
    TmpCell->id=insert_id;
    TmpCell->next=P->next;
    TmpCell->finish_flag=0;
    P->next=TmpCell;
}
void Delete_order_food_list(List_order_food L)
{
    order_food_Position P,TmpCell;
    P=L->next;
    L->next=NULL;
    while (P!=NULL)
    {
        TmpCell=P->next;
        free(P);
        P=TmpCell;
    }
}
List_order_food MakeEmpty_order_food_list(List_order_food L)
{
    if (L!=NULL)
        Delete_order_food_list(L);
    L=(order_food_Position)malloc(sizeof(Node5));
    L->next=NULL;
    return L;
}
void read_data(FILE *fpdict,struct Node1 *food_information,struct Node2 *combo_information)
{
    for(int i=0;i<food_kinds_num;i++)
    {
        fscanf(fpdict,"%s",food_information[i].food_name);
        food_information[i].id=i;
    }
    for(int i=0;i<food_kinds_num;i++)
        qDebug()<<food_information[i].food_name;
    for(int i=0;i<food_kinds_num;i++)
        fscanf(fpdict,"%d",&food_information[i].make_time);
    for (int i=0;i<food_kinds_num;i++)
        fscanf(fpdict,"%d",&food_information[i].cap);
    fscanf(fpdict,"%d %d",&queue_high_num,&queue_low_num);
    char debug_string[50];
    fgets(debug_string,sizeof(debug_string),fpdict);
    for(int i=0;i<combo_kinds_num;i++)
    {
        List_combo_food L;
        L=MakeEmpty_combo_food_list(NULL);
        combo_food_Position P=L;
        char temp_line[256];
        char temp_name[50];
        fgets(temp_line,sizeof(temp_line),fpdict);
        int n;
        for(int j=0,offset=0;sscanf(temp_line+offset,"%49s%n",temp_name,&n)==1;++j)
        {
            if(j==0)
                strcpy(combo_information[i].combo_name, temp_name);
            else
            {
                combo_food_list_insert(temp_name,L,P,food_information,food_kinds_num);
                P=P->next;
            }
            offset+=n;
        }
        combo_information[i].food_list=L;
        combo_information[i].id=i;
    }

}
void data_test(struct Node1 *food_information,struct Node2 *combo_information,List_order L_order)
{
    for(int i=0;i<food_kinds_num;i++)
    {
        qDebug()<<food_information[i].food_name<<food_information[i].id<<food_information[i].cap<<food_information[i].make_time;
    }
    for(int i=0;i<combo_kinds_num;i++)
    {
        printf("%s\n",combo_information[i].combo_name);
        combo_food_Position P=combo_information[i].food_list->next;
        while (P!=NULL)
        {
            printf("%s ",food_information[P->id].food_name);
            P=P->next;
        }
        printf("\n");
    }
    for(order_Position idx1=L_order->next;idx1!=NULL;idx1=idx1->next)
    {
        printf("%d\n",idx1->time);
        for(order_food_Position idx2=idx1->order_food_list->next;idx2!=NULL;idx2=idx2->next)
            printf("%s\n",food_information[idx2->id]);
    }
}
void read_order(List_order L,struct Node1 *food_array,struct Node2 *combo_array)
{
    char temp_line[256];
    char temp[50];
    order_Position P1=L;
    int order_num;
    scanf("%d",&order_num);
    getchar();
    for(int i=1;i<=order_num;i++)
    {
        fgets(temp_line,sizeof(temp_line),stdin);
        int n;
        List_order_food L_order_food=MakeEmpty_order_food_list(NULL);
        order_food_Position P2=L_order_food;
        for(int i=0,offset=0;sscanf(temp_line+offset,"%49s%n",temp,&n)==1;++i)
        {
            if(i==0)
            {
                int hour,minute,second;
                sscanf(temp,"%d:%d:%d",&hour,&minute,&second);
                order_list_insert(L,type_conversion_str_to_second(hour,minute,second),P1,L_order_food);
                P1=P1->next;
            }
            else
            {
                int find_id=combo_id_find(combo_array,temp);
                if(find_id!=-1)
                {
                    combo_array[find_id].food_list->next;
                    for(combo_food_Position idx=combo_array[find_id].food_list->next;idx!=NULL;idx=idx->next)
                    {
                        order_food_list_insert(L_order_food,idx->id,P2);
                        P2=P2->next;
                    }
                }
                else
                {
                    find_id=food_id_find(food_array,temp,food_kinds_num);
                    order_food_list_insert(L_order_food,find_id,P2);
                    P2=P2->next;
                }
            }
            offset+=n;
        }
    }
}
int Qfood_id_find(struct Node1 *food_array,const char *food_name,int foodnum)
{
    int ans;
    int flag=0;
    for(ans=0;ans<foodnum;ans++)
    {
        if(!strcmp(food_array[ans].food_name,food_name))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        return ans;
    else
    {
        return -1;
    }
}
int Qcombo_id_find(struct Node2 *combo_array,const char *combo_name,int combonum)
{
    int ans;
    int flag=0;
    for(ans=0;ans<combonum;ans++)
    {
        if(!strcmp(combo_array[ans].combo_name,combo_name))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        return ans;
    else
        return -1;
}
void Qorder_list_insert(List_order L,order_Position aim_pos)
{
    order_Position idx=L;
    while(idx->next!=NULL)
        idx=idx->next;
    order_Position P = (order_Position)malloc(sizeof(struct Node4));
    P->order_food_list=aim_pos->order_food_list;
    P->finish_flag=aim_pos->finish_flag;
    P->finish_time=aim_pos->finish_time;
    P->receive_flag=aim_pos->receive_flag;
    P->time=aim_pos->time;
    P->next=aim_pos->next;
    idx->next=P;
}
