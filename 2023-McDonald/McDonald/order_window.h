#ifndef ORDER_WINDOW_H
#define ORDER_WINDOW_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include "Data_Structure.h"

namespace Ui {
class order_window;
}

class order_window : public QWidget
{
    Q_OBJECT

public:
    explicit order_window(QWidget *parent = nullptr);
    ~order_window();
    void displayFoodInformation(Node1 foodInformation[], int foodCount);
    void displayComboInformation(Node1 foodInformation[],Node2 comboInformation[], int comboCount);
    void setFoodInformation(struct Node1 *foodInfo);
    void setComboInformation(struct Node2 *comboInfo);
    void setOrderListHead(order_Position orderListHead);
private slots:
    void on_pushButton_clicked();
    void updateClock();
    void on_order_button_clicked();
    void on_speedUpButton_clicked();
    void on_slowDownButton_clicked();
    void updateFoodStorage();
private:
    Ui::order_window *ui;
    QTimer *timer;
    QTime currentTime;
    int speedFactor;
    int timerInterval;
    int foodnum;
    int combonum;
    struct Node1 *food_information;
    struct Node2 *combo_information;
    order_Position order_list_head;
};

#endif // ORDER_WINDOW_H
