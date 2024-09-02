#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "order_window.h"
#include "Data_Structure.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class BUPT_McDonald;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_read_data_clicked();
    void on_begin_order_clicked();

private:
    Ui::BUPT_McDonald *ui;
    order_window *orderpage;
    int food_kinds_num;
    int combo_kinds_num;
    Node1* food_information;
    Node2* combo_information;
    List_order L_order;
    List_combo_food L;
};
#endif // MAINWINDOW_H
