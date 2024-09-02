#include <iostream>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "Data_Structure.h"
int type_conversion_str_to_second(int hour,int minute,int second)
{
    int init_hour=7,init_minute=0,init_second=0;
    int ans=(hour-init_hour)*3600+(minute-init_minute)*60+(second-init_second);
    return ans;
}
void type_conversion_second_to_str(FILE *fpoutput,int clock)
{
    int hour,minute,second;
    hour=clock/3600;
    clock-=hour*3600;
    minute=clock/60;
    clock-=minute*60;
    second=clock;
    hour+=7;
    fprintf(fpoutput,"%02d:%02d:%02d\n",hour,minute,second);
}
int QStringToSeconds(const QString& timeStr)
{
    // 拆分字符串，获取小时、分钟和秒
    QStringList timeParts = timeStr.split(":");
    //qDebug() << "拆分结果:" << timeParts;  // 调试输出

    if (timeParts.size() != 3)
    {
        // 如果时间格式不正确，返回-1表示错误
        qDebug() << "时间格式不正确:" << timeStr;
        return -1;
    }

    bool ok;
    int hours = timeParts[0].toInt(&ok);
    if (!ok)
    {
        qDebug() << "小时转换错误:" << timeParts[0];
        return -1;
    }
    int minutes = timeParts[1].toInt(&ok);
    if (!ok)
    {
        qDebug() << "分钟转换错误:" << timeParts[1];
        return -1;
    }
    int seconds = timeParts[2].toInt(&ok);
    if (!ok)
    {
        qDebug() << "秒钟转换错误:" << timeParts[2];
        return -1;
    }

    // 计算总秒数
    int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
    //qDebug() << "计算总秒数:" << totalSeconds;  // 调试输出
    return totalSeconds;
}
void make_food(struct Node1 *food_information,int clock,int foodnum)
{
    for(int i=0;i<foodnum;i++)
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
void deal_with_this_order(order_Position P,struct Node1 *food_information,int clock,int *current_queue_length)
{
    int ans=0;
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
        if(idx1->finish_flag==0)
            order_finish_flag=0;
    }
    if(order_finish_flag)
    {
        P->finish_flag=1;
        P->finish_time=clock;
    }
    else
        *current_queue_length+=1;
}
int deal_with_order(List_order L_order,struct Node1 *food_information,int clock)
{
    for(order_Position idx1=L_order->next;idx1!=NULL;idx1=idx1->next)
    {
        if(idx1->receive_flag==0||idx1->finish_flag==1)
            continue;
        else
        {
            for(order_food_Position idx2=idx1->order_food_list->next;idx2!=NULL;idx2=idx2->next)
            {
                if(food_information[idx2->id].current>0&&idx2->finish_flag==0)
                {
                    idx2->finish_flag=1;
                    food_information[idx2->id].current--;
                }
            }
            int order_finish_flag=1;
            for(order_food_Position idx2=idx1->order_food_list->next;idx2!=NULL;idx2=idx2->next)
            {
                if(idx2->finish_flag==0)
                    order_finish_flag=0;
            }
            if(order_finish_flag)
            {
                idx1->finish_flag=1;
                idx1->finish_time=clock;
            }
        }
    }
    int queue_length=0;
    for(order_Position idx1=L_order->next;idx1!=NULL;idx1=idx1->next)
    {
        if(idx1->receive_flag&&idx1->finish_flag==0)
            queue_length++;
    }
    return queue_length;
}
int queue_is_empty(List_order L_order,int clock)
{
    int ans=1;
    for(order_Position idx=L_order->next;idx!=NULL;idx=idx->next)
    {
        if(idx->receive_flag==1&&idx->finish_flag==0)
            ans=0;
    }
    return ans;
}
void working_simulation(struct Node1 *food_information,List_order L_order,int foodnum)
{
    int clock=0;
    int receiving_flag=1;
    int current_queue_length;
    int *ptr_debug=&current_queue_length;
    order_Position P=L_order->next;
    while(clock<=54000||!queue_is_empty(L_order,clock))
    {
        current_queue_length=deal_with_order(L_order,food_information,clock);
        if(P!=NULL&&clock<=54000&&clock==P->time&&receiving_flag==1)
        {
            P->receive_flag=1;
            deal_with_this_order(P,food_information,clock,ptr_debug);
            P=P->next;
        }
        else if(P!=NULL&&clock<=54000&&clock==P->time&&receiving_flag==0)
            P=P->next;
        make_food(food_information,clock,foodnum);
        if(current_queue_length>queue_high_num) receiving_flag=0;
        if(current_queue_length<queue_low_num) receiving_flag=1;
        clock++;
    }
}
void Qworking_simulation(struct Node1 *food_information,List_order L_order,int foodnum,int time,int foodStore[])
{
    int clock=0;
    int receiving_flag=1;
    int current_queue_length;
    int *ptr_debug=&current_queue_length;
    order_Position P=L_order->next;
    while(clock<=time)
    {
        current_queue_length=deal_with_order(L_order,food_information,clock);
        if(P!=NULL&&clock<=54000&&clock==P->time&&receiving_flag==1)
        {
            P->receive_flag=1;
            deal_with_this_order(P,food_information,clock,ptr_debug);
            P=P->next;
        }
        else if(P!=NULL&&clock<=54000&&clock==P->time&&receiving_flag==0)
            P=P->next;
        make_food(food_information,clock,foodnum);
        if(current_queue_length>queue_high_num) receiving_flag=0;
        if(current_queue_length<queue_low_num) receiving_flag=1;
        clock++;
    }
    for(int i=0;i<foodnum;i++)
    {
        foodStore[i]=food_information[i].current;
    }
}
