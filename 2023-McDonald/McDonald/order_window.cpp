#include "order_window.h"
#include "ui_order_window.h"
#include "mainwindow.h"
#include "Data_Structure.h"
#include "input.h"
#include "work.h"
#include <QMessageBox>
order_window::order_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::order_window)
{
    ui->setupUi(this);

    currentTime = QTime(7, 0, 0);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &order_window::updateClock);
    timerInterval = 1000;
    timer->start(timerInterval);
    speedFactor = 1;
    ui->clockLabel->setText(currentTime.toString("HH:mm:ss"));
    ui->outputtableWidget->setColumnCount(2);
    QStringList headers;
    headers << "订单ID" << "订单状态";
    ui->outputtableWidget->setHorizontalHeaderLabels(headers);
}

order_window::~order_window()
{
    delete ui;
}
void order_window::setFoodInformation(struct Node1 *foodInfo)
{
    food_information = foodInfo;
}

void order_window::setComboInformation(struct Node2 *comboInfo)
{
    combo_information = comboInfo;
}

void order_window::setOrderListHead(order_Position orderListHead)
{
    order_list_head = orderListHead;
}
void order_window::on_pushButton_clicked()
{
    data_read_state=0;
    this->close();
    MainWindow *main=new MainWindow;
    main->show();
}
void order_window::displayFoodInformation(Node1 foodinformation[],int foodcount)
{
    FILE *fpdict=fopen("menu.txt","r");
    fscanf(fpdict,"%d %d",&foodnum,&combonum);
    ui->foodtableWidget->setRowCount(foodcount);
    ui->foodtableWidget->setColumnCount(3);
    for (int row = 0; row < ui->foodtableWidget->rowCount(); ++row)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        ui->foodtableWidget->setItem(row, 0, item);
    }
    QStringList headers;
    headers<<"单品"<<"单品名称"<<"当前备餐数量";
    ui->foodtableWidget->setHorizontalHeaderLabels(headers);
    for(int i=0;i<foodcount;i++)
        ui->foodtableWidget->setItem(i, 1, new QTableWidgetItem(foodinformation[i].food_name));
}
void order_window::displayComboInformation(Node1 foodinformation[],Node2 comboinformation[],int combocount)
{
    ui->combotableWidget->setRowCount(combocount);
    ui->combotableWidget->setColumnCount(6);
    for (int row = 0; row < ui->combotableWidget->rowCount(); ++row)
    {
        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(checkItem->flags() | Qt::ItemIsUserCheckable);
        checkItem->setCheckState(Qt::Unchecked);
        ui->combotableWidget->setItem(row, 0, checkItem);
    }
    QStringList headers;
    headers<<"套餐"<<"套餐名称"<<"所包含食物";
    ui->combotableWidget->setHorizontalHeaderLabels(headers);
    for(int i=0;i<combocount;i++)
    {
        ui->combotableWidget->setItem(i, 1, new QTableWidgetItem(comboinformation[i].combo_name));
        combo_food_Position P=comboinformation[i].food_list->next;
        int j=2;
        while(P!=NULL)
        {
            ui->combotableWidget->setItem(i,j,new QTableWidgetItem(foodinformation[P->id].food_name));
            P=P->next;
            j++;
        }
    }
}
void order_window::updateClock()
{
    currentTime = currentTime.addSecs(speedFactor);
    if (currentTime > QTime(22, 0, 0))
    {
        timer->stop();
        QMessageBox::information(this, "提示", "今天已经下班了，明天再来吧！");
    }
    ui->clockLabel->setText(currentTime.toString("HH:mm:ss"));
    updateFoodStorage();
}
void order_window::on_order_button_clicked()
{

    QString currentTime = ui->clockLabel->text();
    int orderTimeInSeconds = QStringToSeconds(currentTime)-25200;
    order_Position newOrder = (order_Position)malloc(sizeof(struct Node4));
    newOrder->time = orderTimeInSeconds;
    newOrder->order_food_list = MakeEmpty_order_food_list(NULL);
    newOrder->finish_flag = 0;
    newOrder->receive_flag = 0;
    newOrder->next = NULL;
    order_food_Position foodPos = newOrder->order_food_list;
    int empty_flag=0;
    for (int row = 0; row < ui->foodtableWidget->rowCount(); ++row)
    {
        QTableWidgetItem *item = ui->foodtableWidget->item(row, 0);
        if (item->checkState() == Qt::Checked)
        {
            empty_flag=1;
            QTableWidgetItem *item1 = ui->foodtableWidget->item(row, 1);
            int food_id = Qfood_id_find(food_information,item1->text().toStdString().c_str() ,foodnum);
            order_food_list_insert(newOrder->order_food_list, food_id, foodPos);
            foodPos = foodPos->next;
        }
    }
    for (int row = 0; row < ui->combotableWidget->rowCount(); ++row)
    {
        QTableWidgetItem *item = ui->combotableWidget->item(row, 0);
        if (item->checkState() == Qt::Checked)
        {
            empty_flag=1;
            QTableWidgetItem *item1 = ui->combotableWidget->item(row, 1);
            int combo_id = Qcombo_id_find(combo_information, item1->text().toStdString().c_str(),combonum);
            if (combo_id != -1)
            {
                combo_food_Position comboPos = combo_information[combo_id].food_list->next;
                while (comboPos != NULL)
                {
                    order_food_list_insert(newOrder->order_food_list, comboPos->id, foodPos);
                    foodPos = foodPos->next;
                    comboPos = comboPos->next;
                }
            }
        }
    }
    if(empty_flag)
    {
        Qorder_list_insert(order_list_head,newOrder);
        QMessageBox::information(this, "订单已下单", "您的订单已成功下单！");

         working_simulation(food_information,order_list_head,foodnum);
        ui->outputtableWidget->clear();
        int rowCount = 0;
        order_Position current = order_list_head->next;
        while (current != NULL)
        {
            rowCount++;
            current = current->next;
        }
        ui->outputtableWidget->setRowCount(rowCount);
        ui->outputtableWidget->setColumnCount(3);
        QStringList headers;
        headers << "订单ID" << "下单时间" << "状态";
        ui->outputtableWidget->setHorizontalHeaderLabels(headers);
        current = order_list_head->next;
        int row = 0;
        while (current != NULL)
        {
            QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(row + 1));
            ui->outputtableWidget->setItem(row, 0, idItem);
            int orderTime = current->time + 25200;
            QString orderTimeStr = QTime::fromMSecsSinceStartOfDay(orderTime * 1000).toString("hh:mm:ss");
            QTableWidgetItem *orderTimeItem = new QTableWidgetItem(orderTimeStr);
            ui->outputtableWidget->setItem(row, 1, orderTimeItem);
            QString status;
            if (current->finish_flag == 0 || current->receive_flag == 0)
            {
                status = "Fail";
            }
            else
            {
                int finishTime = current->finish_time + 25200;
                status = QTime::fromMSecsSinceStartOfDay(finishTime * 1000).toString("hh:mm:ss");
            }
            QTableWidgetItem *statusItem = new QTableWidgetItem(status);
            ui->outputtableWidget->setItem(row, 2, statusItem);

            current = current->next;
            row++;
        }
        FILE *fpoutput=fopen("output.txt","w+");
        for(order_Position idx=order_list_head->next;idx!=NULL;idx=idx->next)
        {
            if(idx->finish_flag==1)
                type_conversion_second_to_str(fpoutput,idx->finish_time);
            else
                fprintf(fpoutput,"Fail\n");
        }
        current = order_list_head->next;
        while (current != NULL)
        {
            current->finish_flag = 0;
            current->receive_flag = 0;
            order_food_Position current1=current->order_food_list->next;
            while(current1!=NULL)
            {
                current1->finish_flag=0;;
                current1=current1->next;
            }
            current = current->next;
        }
        for(int i=0;i<foodnum;i++)
        {
            food_information[i].current=0;
            food_information[i].schedule=0;
        }
    }
    else
    QMessageBox::information(this, "来自店员的疑惑", "您还什么都没有点呢");
}
void order_window::on_speedUpButton_clicked()
{
    timerInterval /= 2;
    if (timerInterval < 10)
    {
        timerInterval = 10;
        QMessageBox::information(this, "提示", "运行速度已达最快！");
    }
    timer->start(timerInterval);
}
void order_window::on_slowDownButton_clicked()
{
    timerInterval *= 2;
    if (timerInterval > 1000)
    {
        timerInterval = 1000;
        QMessageBox::information(this, "提示", "运行速度已达最慢！");
    }
    timer->start(timerInterval);
}
void order_window::updateFoodStorage()
{
    QString currentTime = ui->clockLabel->text();
    int currentTimeInSeconds = QStringToSeconds(currentTime)-25200;
    int foodStore[foodnum];
    Qworking_simulation(food_information,order_list_head,foodnum,currentTimeInSeconds,foodStore);
    order_Position current = order_list_head->next;
    current = order_list_head->next;
    while (current != NULL)
    {
        current->finish_flag = 0;
        current->receive_flag = 0;
        order_food_Position current1=current->order_food_list->next;
        while(current1!=NULL)
        {
            current1->finish_flag=0;;
            current1=current1->next;
        }
        current = current->next;
    }
    for(int i=0;i<foodnum;i++)
    {
        food_information[i].current=0;
        food_information[i].schedule=0;
    }
    for(int i=0;i<foodnum;i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(foodStore[i]));
        ui->foodtableWidget->setItem(i, 2, item);
    }
}
