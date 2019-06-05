/********************************************************************************
** Form generated from reading UI file 'main_view.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_VIEW_H
#define UI_MAIN_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_view
{
public:
    QLabel *label;
    QTableView *ready_tableView;
    QTableView *ask_tableView;
    QTableView *using_tableView;
    QTableView *finished_tableView;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTableView *data_tableView;
    QPushButton *start_pushButton;
    QLabel *label_6;
    QLabel *time_label;
    QLabel *error_label;

    void setupUi(QWidget *Main_view)
    {
        if (Main_view->objectName().isEmpty())
            Main_view->setObjectName(QStringLiteral("Main_view"));
        Main_view->resize(822, 556);
        label = new QLabel(Main_view);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 10, 71, 21));
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        ready_tableView = new QTableView(Main_view);
        ready_tableView->setObjectName(QStringLiteral("ready_tableView"));
        ready_tableView->setGeometry(QRect(20, 40, 221, 231));
        ask_tableView = new QTableView(Main_view);
        ask_tableView->setObjectName(QStringLiteral("ask_tableView"));
        ask_tableView->setGeometry(QRect(280, 40, 221, 231));
        using_tableView = new QTableView(Main_view);
        using_tableView->setObjectName(QStringLiteral("using_tableView"));
        using_tableView->setGeometry(QRect(20, 310, 221, 231));
        finished_tableView = new QTableView(Main_view);
        finished_tableView->setObjectName(QStringLiteral("finished_tableView"));
        finished_tableView->setGeometry(QRect(280, 310, 221, 231));
        label_2 = new QLabel(Main_view);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 10, 221, 21));
        label_2->setFont(font);
        label_3 = new QLabel(Main_view);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 280, 221, 21));
        label_3->setFont(font);
        label_4 = new QLabel(Main_view);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(350, 280, 91, 21));
        label_4->setFont(font);
        label_5 = new QLabel(Main_view);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(570, 10, 221, 21));
        label_5->setFont(font);
        data_tableView = new QTableView(Main_view);
        data_tableView->setObjectName(QStringLiteral("data_tableView"));
        data_tableView->setGeometry(QRect(540, 40, 261, 421));
        start_pushButton = new QPushButton(Main_view);
        start_pushButton->setObjectName(QStringLiteral("start_pushButton"));
        start_pushButton->setGeometry(QRect(680, 490, 121, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Aharoni"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        start_pushButton->setFont(font1);
        label_6 = new QLabel(Main_view);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(540, 490, 71, 41));
        label_6->setFont(font1);
        time_label = new QLabel(Main_view);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(630, 490, 51, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Aharoni"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        time_label->setFont(font2);
        error_label = new QLabel(Main_view);
        error_label->setObjectName(QStringLiteral("error_label"));
        error_label->setGeometry(QRect(540, 469, 261, 16));

        retranslateUi(Main_view);

        QMetaObject::connectSlotsByName(Main_view);
    } // setupUi

    void retranslateUi(QWidget *Main_view)
    {
        Main_view->setWindowTitle(QApplication::translate("Main_view", "Form", 0));
        label->setText(QApplication::translate("Main_view", "Ready", 0));
        label_2->setText(QApplication::translate("Main_view", "Asking for permission", 0));
        label_3->setText(QApplication::translate("Main_view", "Reading / Writing", 0));
        label_4->setText(QApplication::translate("Main_view", "Finished", 0));
        label_5->setText(QApplication::translate("Main_view", "Reader / Writer List", 0));
        start_pushButton->setText(QApplication::translate("Main_view", "Start", 0));
        label_6->setText(QApplication::translate("Main_view", "TIME :", 0));
        time_label->setText(QApplication::translate("Main_view", "0", 0));
        error_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Main_view: public Ui_Main_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_VIEW_H
