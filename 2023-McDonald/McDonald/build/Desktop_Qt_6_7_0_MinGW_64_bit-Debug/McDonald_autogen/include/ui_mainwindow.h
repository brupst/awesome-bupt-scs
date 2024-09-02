/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BUPT_McDonald
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *begin_order;
    QPushButton *read_data;

    void setupUi(QMainWindow *BUPT_McDonald)
    {
        if (BUPT_McDonald->objectName().isEmpty())
            BUPT_McDonald->setObjectName("BUPT_McDonald");
        BUPT_McDonald->resize(787, 555);
        centralwidget = new QWidget(BUPT_McDonald);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    background-color: rgb(255, 199, 44);\n"
"}\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 771, 371));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 380, 411, 41));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 460, 561, 20));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        begin_order = new QPushButton(layoutWidget);
        begin_order->setObjectName("begin_order");

        horizontalLayout->addWidget(begin_order, 0, Qt::AlignHCenter);

        read_data = new QPushButton(layoutWidget);
        read_data->setObjectName("read_data");

        horizontalLayout->addWidget(read_data, 0, Qt::AlignHCenter);

        BUPT_McDonald->setCentralWidget(centralwidget);

        retranslateUi(BUPT_McDonald);

        QMetaObject::connectSlotsByName(BUPT_McDonald);
    } // setupUi

    void retranslateUi(QMainWindow *BUPT_McDonald)
    {
        BUPT_McDonald->setWindowTitle(QCoreApplication::translate("BUPT_McDonald", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("BUPT_McDonald", "<html><head/><body><p><img src=\":/new/prefix1/image/bupt-mcdonald's.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("BUPT_McDonald", "<html><head/><body><p align=\"center\"><img src=\":/new/prefix1/image/bupt-mcdonald's.png\"/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("BUPT_McDonald", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt;\">\346\254\242\350\277\216\344\275\277\347\224\250\351\272\246\345\275\223\345\212\263\347\202\271\351\244\220\347\263\273\347\273\237\357\274\201</span></p></body></html>", nullptr));
        begin_order->setText(QCoreApplication::translate("BUPT_McDonald", "\345\274\200\345\247\213\347\202\271\351\244\220", nullptr));
        read_data->setText(QCoreApplication::translate("BUPT_McDonald", "\350\257\273\345\217\226\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BUPT_McDonald: public Ui_BUPT_McDonald {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
