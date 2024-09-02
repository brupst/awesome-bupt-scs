#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H
extern int food_kinds_num;
extern int combo_kinds_num;
extern int order_num;
extern int queue_low_num;
extern int queue_high_num;
extern int data_read_state;
struct Node3;
typedef struct Node3 *PtrToNode3;
typedef PtrToNode3 List_combo_food;
typedef PtrToNode3 combo_food_Position;
struct Node4;
typedef struct Node4 *PtrToNode4;
typedef PtrToNode4 List_order;
typedef PtrToNode4 order_Position;
struct Node5;
typedef struct Node5 *PtrToNode5;
typedef PtrToNode5 List_order_food;
typedef PtrToNode5 order_food_Position;
struct Node1
{
    char food_name[50];
    int id;
    int current=0;
    int cap;
    int make_time;
    int schedule=0;
};
struct Node2
{
    char combo_name[50];
    int id;
    List_combo_food food_list;
};
struct Node3
{
    int id;
    combo_food_Position next;
};
struct Node4
{
    int time;
    List_order_food order_food_list;
    int finish_flag=0;
    int receive_flag=0;
    int finish_time;
    order_Position next;
};
struct Node5
{
    int id;
    int finish_flag=0;
    order_food_Position next;
};
#endif // DATA_STRUCTURE_H
