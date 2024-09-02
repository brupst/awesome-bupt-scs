#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int food_kinds_num;
int combo_kinds_num;
int order_num;
int queue_low_num;
int queue_high_num;
struct Node3;
struct Node4;
struct Node5;
struct Node6;
typedef struct Node3 *PtrToNode3;
typedef PtrToNode3 List_combo_food;
typedef PtrToNode3 combo_food_Position;
typedef struct Node4 *PtrToNode4;
typedef PtrToNode4 List_order;
typedef PtrToNode4 order_Position;
typedef struct Node5 *PtrToNode5;
typedef PtrToNode5 List_order_food;
typedef PtrToNode5 order_food_Position;
typedef struct Node6 *PtrToNode6;
typedef PtrToNode6 List_debug_queue;
typedef PtrToNode6 debug_queue_Position;
struct Node3 
{
    int id;
    combo_food_Position next;
};
struct Node4 
{
    int time;
    List_order_food order_food_list;
    int finish_flag;
    int receive_flag;
    int finish_time;
    order_Position next;
};
struct Node5 
{
    int id;
    int finish_flag;
    order_food_Position next;
};
struct Node6 
{
    debug_queue_Position right_next;
    order_Position low_next;
};
struct Node1 
{
    char food_name[50];
    int id;
    int current;
    int cap;
    int make_time;
    int schedule;
};
struct Node2 
{
    char combo_name[50];
    int id;
    List_combo_food food_list;
};
void Delete_debug_queue(List_debug_queue L) 
{
    debug_queue_Position P,Tmp;
    P=L->right_next;
    L->right_next=NULL;
    while(P!=NULL) 
    {
        Tmp=P->right_next;
        free(P);
        P=Tmp;
    }
}
 
List_debug_queue MakeEmpty_debug_queue(List_debug_queue L) 
{
    if (L!=NULL)
    Delete_debug_queue(L);
    L=(debug_queue_Position)malloc(sizeof(struct Node6));
    L->low_next=NULL;
    L->right_next=NULL;
    return L;
}
void debug_queue_insert(order_Position P1,debug_queue_Position P2) 
{
    debug_queue_Position P=(debug_queue_Position)malloc(sizeof(struct Node6));
    P->low_next=P1;
    P->right_next=NULL;
    debug_queue_Position temp=P2;
    while(temp->right_next!=NULL) 
    temp=temp->right_next;
    temp->right_next=P;
}
int food_id_find(struct Node1 *food_array,char *food_name) 
{
    int ans;
    int flag=0;
    for(ans=0;ans<food_kinds_num;ans++)
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
    return -1;
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
void combo_food_list_insert(char *food_name,List_combo_food L,combo_food_Position P,struct Node1 *food_array) 
{
    combo_food_Position TmpCell;
    TmpCell =(combo_food_Position)malloc(sizeof(struct Node3));
    TmpCell->id=food_id_find(food_array, food_name);
    TmpCell->next=P->next;
    P->next=TmpCell;
}
void Delete_combo_food_list(List_combo_food L) 
{
    combo_food_Position P,TmpCell;
    P=L->next;
    L->next=NULL;
    while(P!= NULL) 
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
    L=(combo_food_Position)malloc(sizeof(struct Node3));
    L->next=NULL;
    return L;
}
void order_list_insert(List_order L,int order_time,order_Position P,List_order_food L_order_food) 
{
    order_Position TmpCell;
    TmpCell=(order_Position)malloc(sizeof(struct Node4));
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
    while (P!=NULL) 
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
    L=(order_Position)malloc(sizeof(struct Node4));
    L->next=NULL;
    return L;
}
void order_food_list_insert(List_order_food L,int insert_id,order_food_Position P) 
{
    order_food_Position TmpCell;
    TmpCell=(order_food_Position)malloc(sizeof(struct Node5));
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
    L=(order_food_Position)malloc(sizeof(struct Node5));
    L->next=NULL;
    return L;
}
void read_data(FILE *fpdict, struct Node1 *food_information,struct Node2 *combo_information) 
{
    for(int i=0;i<food_kinds_num;i++) 
    {
        fscanf(fpdict,"%s",food_information[i].food_name);
        food_information[i].id=i;
    }
    for(int i=0;i<food_kinds_num;i++)
    fscanf(fpdict, "%d",&food_information[i].make_time);
    for(int i=0;i<food_kinds_num;i++)
    fscanf(fpdict, "%d", &food_information[i].cap);
    fscanf(fpdict,"%d %d",&queue_high_num,&queue_low_num);
    char debug_string[50];
    fgets(debug_string,sizeof(debug_string),fpdict);
    for(int i=0; i<combo_kinds_num;i++) 
    {
        List_combo_food L;
        L=MakeEmpty_combo_food_list(NULL);
        combo_food_Position P=L;
        char temp_line[256];
        char temp_name[50];
        fgets(temp_line,sizeof(temp_line),fpdict);
        int n;
        for(int j=0,offset=0;sscanf(temp_line+offset,"%49s%n",temp_name,&n)==1;j++) 
        {
            if (j==0)
            strcpy(combo_information[i].combo_name,temp_name);
            else 
            {
                combo_food_list_insert(temp_name,L,P, food_information);
                P=P->next;
            }
            offset+=n;
        }
        combo_information[i].food_list=L;
        combo_information[i].id=i;
    }
}
void read_order(List_order L,struct Node1 *food_array,struct Node2 *combo_array) {
    order_Position P1=L;
    scanf("%d",&order_num);
    getchar();
    for(int i=0; i<order_num;i++) 
    {
        List_order_food L_order_food=MakeEmpty_order_food_list(NULL);
        order_food_Position P2=L_order_food;
        int hour,minute,second;
        scanf("%d:%d:%d",&hour,&minute,&second);
        order_list_insert(L,type_conversion_str_to_second(hour, minute, second),P1,L_order_food);
        char temp[50];
        scanf("%s",temp);
        int find_id = combo_id_find(combo_array,temp);
        if(find_id!=-1) 
        {
            combo_array[find_id].food_list->next;
            for(combo_food_Position idx=combo_array[find_id].food_list->next;idx != NULL;idx = idx->next) 
            {
                order_food_list_insert(L_order_food,idx->id,P2);
                P2=P2->next;
            }
        } 
        else 
        {
            find_id=food_id_find(food_array,temp);
            order_food_list_insert(L_order_food,find_id,P2);
            P2=P2->next;
        }
        P1=P1->next;
    }
}
void make_food(struct Node1 *food_information,int clock) 
{
    for(int i=0;i<food_kinds_num;i++) 
    {
        if(food_information[i].current<food_information[i].cap)
        food_information[i].schedule++;
        if(food_information[i].schedule>=food_information[i].make_time) 
        {
            food_information[i].schedule%=food_information[i].make_time;
            food_information[i].current++;
        }
    }
}
int deal_with_order(List_debug_queue debug_queue,struct Node1 *food_information,int clock) 
{
    int queue_length=0;
    debug_queue_Position prev=debug_queue;
    for(debug_queue_Position idx1=debug_queue->right_next;idx1 != NULL;) 
    {
        for(order_food_Position idx2=idx1->low_next->order_food_list->next;idx2!=NULL;idx2 = idx2->next)
        {
            if (food_information[idx2->id].current>0&&idx2->finish_flag==0) 
            {
                idx2->finish_flag=1;
                food_information[idx2->id].current--;
            }
        }
        int order_finish_flag = 1;
        for(order_food_Position idx2=idx1->low_next->order_food_list->next;idx2 != NULL;idx2 = idx2->next) 
        {
            if(idx2->finish_flag==0) 
            {
                order_finish_flag=0;
                break;
            }
        }
        if(order_finish_flag) 
        {
            idx1->low_next->finish_flag=1;
            idx1->low_next->finish_time=clock;
        }
        if (idx1->low_next->finish_flag==0) 
        {
            queue_length++;
            prev=idx1;
            idx1=idx1->right_next;
        } 
        else 
        {
            debug_queue_Position tmp=idx1;
            prev->right_next=idx1->right_next;
            idx1=idx1->right_next;
            free(tmp);
        }
    }
    return queue_length;
}
void deal_with_this_order(order_Position P,struct Node1 *food_information,int clock,int *current_queue_length,debug_queue_Position P1,List_debug_queue debug_queue) 
{
    int ans = 0;
    for(order_food_Position idx1=P->order_food_list->next;idx1!=NULL;idx1=idx1->next) 
    {
        if(food_information[idx1->id].current>0&&idx1->finish_flag==0) 
        {
            idx1->finish_flag=1;
            food_information[idx1->id].current--;
        }
    }
    int order_finish_flag=1;
    for(order_food_Position idx1=P->order_food_list->next;idx1!=NULL;idx1=idx1->next) 
    {
        if (idx1->finish_flag==0)
        order_finish_flag=0;
    }
    if(order_finish_flag) 
    {
        P->finish_flag=1;
        P->finish_time=clock;
    } 
    else 
    {
        *current_queue_length+=1;
        debug_queue_insert(P,P1);
    }
}
int queue_is_empty(List_debug_queue debug_queue, int clock) 
{
    int ans=1;
    if(debug_queue->right_next!=NULL)
    ans=0;
    return ans;
}
void working_simulation(struct Node1 *food_information,List_order L_order,List_debug_queue debug_queue) 
{
    int clock=0;
    int receiving_flag=1;
    int current_queue_length;
    int *ptr_debug=&current_queue_length;
    order_Position P=L_order->next;
    while(clock<=54000||!queue_is_empty(debug_queue,clock)) 
    {
        current_queue_length=deal_with_order(debug_queue,food_information,clock);
        if(P!=NULL&&clock<=54000&&clock==P->time&&receiving_flag==1) 
        {
            P->receive_flag=1;
            deal_with_this_order(P,food_information,clock, ptr_debug,debug_queue,debug_queue);
            P=P->next;
        } 
        else if(P!=NULL&&clock<=54000&&clock==P->time&&receiving_flag==0) 
        P=P->next;
        make_food(food_information,clock);
        if(current_queue_length > queue_high_num) receiving_flag=0;
        if(current_queue_length < queue_low_num) receiving_flag=1;
        clock++;
    }
}
int type_conversion_str_to_second(int hour, int minute, int second) 
{
    int init_hour=7,init_minute=0,init_second=0;
    int ans=(hour-init_hour)*3600+(minute-init_minute)*60+(second-init_second);
    return ans;
}
void type_conversion_second_to_str(int clock) 
{
    int hour,minute,second;
    hour=clock/3600;
    clock-=hour*3600;
    minute=clock/60;
    clock-=minute*60;
    second=clock;
    hour+=7;
    printf("%02d:%02d:%02d\n",hour,minute,second);
}
void output(List_order L_order)
{
    for(order_Position idx=L_order->next;idx!=NULL;idx=idx->next) 
    {
        if (idx->finish_flag==1)
        type_conversion_second_to_str(idx->finish_time);
        else
        printf("Fail\n");
    }
}
 
void release_all_memory(List_order L_order) 
{
    for(order_Position idx1=L_order->next;idx1!=NULL;idx1=idx1->next) 
    {
        Delete_order_food_list(idx1->order_food_list);
        free(idx1->order_food_list);
    }
    Delete_order_list(L_order);
    free(L_order);
}
int main() 
{
    FILE *fpdict;
    fpdict = fopen("dict.dic","r");
    if (fpdict == NULL) 
    {
        perror("Error opening dict file");
        return -1;
    }
    fscanf(fpdict,"%d %d",&food_kinds_num,&combo_kinds_num);
    struct Node1 food_information[food_kinds_num];
    for (int i=0; i<food_kinds_num;i++) 
    {
        food_information[i].current=0;
        food_information[i].schedule=0;
    }
    struct Node2 combo_information[combo_kinds_num];
    List_order L_order=MakeEmpty_order_list(NULL);
    List_debug_queue debug_queue=MakeEmpty_debug_queue(NULL);
    read_data(fpdict,food_information,combo_information);
    fclose(fpdict);
    read_order(L_order,food_information,combo_information);
    working_simulation(food_information,L_order,debug_queue);
    output(L_order);
    release_all_memory(L_order);
    Delete_debug_queue(debug_queue);
    free(debug_queue);
    return 0;
}
//The code is created by Liunanfu 
