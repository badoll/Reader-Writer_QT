#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include <QApplication>
#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>
#include <QList>
#include <QPushButton>
#include <QModelIndex>
#include <QVariant>
#include <QTimer>
#include <QTimerEvent>
#include <QString>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "User.h"
#include "global_var.h"

namespace Ui {
class Main_view;
}

class Main_view : public QWidget
{
    /*
     * 继承自Qt的内部文件，一定在类中加上Q_OBJECT的宏定义，
     * Qt会使用MOC将改文件重新编译成moc_mainwindow.cpp文件，这个才是原始的C++类的文件。
     * 所以Qt内置的类文件都不是原生态的C++类，需要Qt编译器再处理，
     * 所以继承子Qt的类一定要添加该宏定义，否则编译一定不通过。
     */
    Q_OBJECT

public:
    explicit Main_view(QWidget *parent = 0);
    ~Main_view();

    friend class Controller;
    friend void add_item_to_tableview(int seq, char user_type, int time, int status, Main_view* mainview);
    friend void remove_item_from_tableview(int seq, int status, Main_view* mainview);

    void set_initialview(std::vector<User*>);
    void set_changedview(const User*,const string,const int);
    void set_errorview();
    void set_buttonstatus(bool);
    void update_time();
    void clear();
    QPushButton* get_start_pushButton();

private:
    Ui::Main_view *ui;
    std::vector<QStandardItemModel*>* model_list;
    std::vector<QTableView*>* tableview_list;
};

#endif // MAIN_VIEW_H
