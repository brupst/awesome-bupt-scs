#ifndef WORK_H
#define WORK_H
#include <QString>
#include "Data_Structure.h"
int type_conversion_str_to_second(int hour,int minute,int second);
void type_conversion_second_to_str(FILE *fpoutput,int clock);
int QStringToSeconds(const QString& timeStr);
void make_food(struct Node1 *food_information,int clock,int foodnum);
void deal_with_this_order(order_Position P,struct Node1 *food_information,int clock,int *current_queue_length);
int deal_with_order(List_order L_order,struct Node1 *food_information,int clock);
int queue_is_empty(List_order L_order,int clock);
void working_simulation(struct Node1 *food_information,List_order L_order,int foodnum);
void Qworking_simulation(struct Node1 *food_information,List_order L_order,int foodnum,int time,int foodStore[]);
#endif // WORK_H
