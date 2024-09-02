#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Data_Structure.h"
#include "input.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BUPT_McDonald),
    orderpage(nullptr),
    food_information(nullptr),
    combo_information(nullptr),
    food_kinds_num(0),
    combo_kinds_num(0),
    L_order(MakeEmpty_order_list(NULL)),
    L(nullptr)
{
    ui->setupUi(this);


}
MainWindow::~MainWindow()
{
    delete ui;
    delete[] food_information;
    delete[] combo_information;
    while (L_order!=nullptr)
    {
        List_order temp = L_order;
        L_order = L_order->next;
        delete temp;
    }
    for (int i = 0; i < combo_kinds_num; ++i)
    {
        List_combo_food current = combo_information[i].food_list;
        while (current != nullptr) {
            List_combo_food temp = current;
            current = current->next;
            delete temp;
        }
    }
}
void MainWindow::on_read_data_clicked()
{
    FILE *fpdict;
    fpdict=fopen("menu.txt","r");
    if(fpdict==NULL)
        QMessageBox::information(this,"读取错误","未读取到菜单或读取失败！");
    else
    {
        fscanf(fpdict,"%d %d",&food_kinds_num,&combo_kinds_num);
        food_information = new Node1[food_kinds_num];
        combo_information = new Node2[combo_kinds_num];
        List_order L_order = MakeEmpty_order_list(NULL);
        for(int i=0;i<food_kinds_num;i++)
        {
            fscanf(fpdict,"%s",food_information[i].food_name);
            food_information[i].id=i;
        }
        for(int i=0;i<food_kinds_num;i++)
            fscanf(fpdict,"%d",&food_information[i].make_time);
        for (int i=0;i<food_kinds_num;i++)
            fscanf(fpdict,"%d",&food_information[i].cap);
        fscanf(fpdict,"%d %d",&queue_high_num,&queue_low_num);
        char debug_string[50];
        fgets(debug_string,sizeof(debug_string),fpdict);
        /*for(int i=0;i<food_kinds_num;i++)
            qDebug()<<std::strlen(food_information[i].food_name);*/
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
        fclose(fpdict);
        data_read_state=1;
        QMessageBox::information(this, "读取成功", "菜单加载完毕！");
    }
}
void MainWindow::on_begin_order_clicked()
{
    if(data_read_state==0)
        QMessageBox::information(this,"Oops!","你还没有读入菜单呢");
    else
    {
        this->hide();
        order_window *orderpage=new order_window;
        orderpage->setFoodInformation(food_information);
        orderpage->setComboInformation(combo_information);
        orderpage->setOrderListHead(L_order);
        orderpage->show();
        orderpage->displayFoodInformation(food_information,food_kinds_num);
        orderpage->displayComboInformation(food_information,combo_information,combo_kinds_num);
    }
}
