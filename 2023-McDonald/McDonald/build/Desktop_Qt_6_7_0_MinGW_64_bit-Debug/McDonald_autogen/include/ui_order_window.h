/********************************************************************************
** Form generated from reading UI file 'order_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDER_WINDOW_H
#define UI_ORDER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_order_window
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTableWidget *foodtableWidget;
    QLabel *label_3;
    QTableWidget *combotableWidget;
    QPushButton *order_button;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QTableWidget *outputtableWidget;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *clockLabel;
    QVBoxLayout *verticalLayout_2;
    QPushButton *speedUpButton;
    QPushButton *slowDownButton;

    void setupUi(QWidget *order_window)
    {
        if (order_window->objectName().isEmpty())
            order_window->setObjectName("order_window");
        order_window->resize(776, 590);
        order_window->setStyleSheet(QString::fromUtf8("QWidget#order_window \n"
"{\n"
"    background-color: rgb(255, 199, 44);\n"
"}\n"
""));
        layoutWidget = new QWidget(order_window);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 0, 271, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_2->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(order_window);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 59, 361, 521));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        foodtableWidget = new QTableWidget(layoutWidget1);
        foodtableWidget->setObjectName("foodtableWidget");

        verticalLayout->addWidget(foodtableWidget);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        combotableWidget = new QTableWidget(layoutWidget1);
        combotableWidget->setObjectName("combotableWidget");

        verticalLayout->addWidget(combotableWidget);

        order_button = new QPushButton(order_window);
        order_button->setObjectName("order_button");
        order_button->setGeometry(QRect(660, 550, 81, 41));
        layoutWidget2 = new QWidget(order_window);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(370, 100, 391, 451));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        outputtableWidget = new QTableWidget(layoutWidget2);
        outputtableWidget->setObjectName("outputtableWidget");

        horizontalLayout_4->addWidget(outputtableWidget);

        layoutWidget3 = new QWidget(order_window);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(380, 0, 341, 98));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        clockLabel = new QLabel(layoutWidget3);
        clockLabel->setObjectName("clockLabel");

        horizontalLayout_3->addWidget(clockLabel);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        speedUpButton = new QPushButton(layoutWidget3);
        speedUpButton->setObjectName("speedUpButton");

        verticalLayout_2->addWidget(speedUpButton);

        slowDownButton = new QPushButton(layoutWidget3);
        slowDownButton->setObjectName("slowDownButton");

        verticalLayout_2->addWidget(slowDownButton);


        horizontalLayout_5->addLayout(verticalLayout_2);


        retranslateUi(order_window);

        QMetaObject::connectSlotsByName(order_window);
    } // setupUi

    void retranslateUi(QWidget *order_window)
    {
        order_window->setWindowTitle(QCoreApplication::translate("order_window", "Form", nullptr));
        label->setText(QCoreApplication::translate("order_window", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\347\202\271\351\244\220\347\263\273\347\273\237</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("order_window", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247\350\217\234\345\215\225", nullptr));
        label_2->setText(QCoreApplication::translate("order_window", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\215\225\345\223\201</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("order_window", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\245\227\351\244\220</span></p></body></html>", nullptr));
        order_button->setText(QCoreApplication::translate("order_window", "\344\270\213\345\215\225\357\274\201", nullptr));
        label_5->setText(QCoreApplication::translate("order_window", "<html><head/><body><p><span style=\" font-size:16pt;\">\350\256\242\345\215\225\347\212\266\346\200\201</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("order_window", "\345\275\223\345\211\215\346\227\266\351\227\264\344\270\272\357\274\232", nullptr));
        clockLabel->setText(QCoreApplication::translate("order_window", "TextLabel", nullptr));
        speedUpButton->setText(QCoreApplication::translate("order_window", "\345\212\240\351\200\237x2", nullptr));
        slowDownButton->setText(QCoreApplication::translate("order_window", "\345\207\217\351\200\237x2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class order_window: public Ui_order_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_WINDOW_H
