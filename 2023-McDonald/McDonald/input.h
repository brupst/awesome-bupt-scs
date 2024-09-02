#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include "Data_Structure.h"
int food_id_find(struct Node1 *food_array,char *food_name,int foodnum);
int combo_id_find(struct Node2 *combo_array,char *combo_name);
void combo_food_list_insert(char *food_name,List_combo_food L,combo_food_Position P,struct Node1 *food_array,int foodnum);
void Delete_combo_food_list(List_combo_food L);
List_combo_food MakeEmpty_combo_food_list(List_combo_food L);
void order_list_insert(List_order L,int order_time,order_Position P,List_order_food L_order_food);
void Delete_order_list(List_order L);
List_order MakeEmpty_order_list(List_order L);
void order_food_list_insert(List_order_food L,int insert_id,order_food_Position P);
void Delete_order_food_list(List_order_food L);
List_order_food MakeEmpty_order_food_list(List_order_food L);
void read_data(FILE *fpdict,struct Node1 *food_information,struct Node2 *combo_information);
void data_test(struct Node1 *food_information,struct Node2 *combo_information,List_order L_order);
void read_order(List_order L,struct Node1 *food_array,struct Node2 *combo_array);
int Qfood_id_find(struct Node1 *food_array,const char *food_name,int foodnum);
int Qcombo_id_find(struct Node2 *combo_array,const char *combo_name,int combonum);
void Qorder_list_insert(List_order L,order_Position aim_pos);
#endif // INPUT_H
