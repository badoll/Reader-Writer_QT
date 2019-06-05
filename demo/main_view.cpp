#include "Main_view.h"
#include "ui_main_view.h"
using namespace std;

static map<string,int> status_list{{"ready",0},{"ask",1},{"use",2},{"finish",3}};
QStandardItemModel* set_tabletitle(QTableView*);
void set_datalist(QTableView*,vector<User*>);
int get_status(string status);

Main_view::Main_view(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Main_view),
    model_list(new vector<QStandardItemModel*>(4)),
    tableview_list(new vector<QTableView*>(4))
{
    ui->setupUi(this);
    tableview_list->at(0) = ui->ready_tableView;
    tableview_list->at(1) = ui->ask_tableView;
    tableview_list->at(2) = ui->using_tableView;
    tableview_list->at(3) = ui->finished_tableView;
}

Main_view::~Main_view()
{
    delete ui;
    for (vector<QTableView*>::iterator it = tableview_list->begin(); it != tableview_list->end(); ++it)
        delete *it;
    for (vector<QStandardItemModel*>::iterator it = model_list->begin(); it != model_list->end(); ++it)
        delete *it;
    delete tableview_list;
    delete model_list;
}

QPushButton*
Main_view::get_start_pushButton()
{
    return ui->start_pushButton;
}

void
Main_view::set_errorview()
{
    ui->error_label->setText("data file doesn't exist.");
    ui->error_label->setStyleSheet("font-size:20px;color:red");
    ui->start_pushButton->setDisabled(true);
}

void
Main_view::set_initialview(vector<User*> user_list)
{
    this->setWindowTitle("Reader/Writer");
    model_list->at(0) = set_tabletitle(ui->ready_tableView);
    model_list->at(1) = set_tabletitle(ui->ask_tableView);
    model_list->at(2) = set_tabletitle(ui->using_tableView);
    model_list->at(3) = set_tabletitle(ui->finished_tableView);
    set_datalist(ui->data_tableView,user_list);
}

QStandardItemModel*
set_tabletitle(QTableView* table_view)
{
    QStandardItemModel  *model = new QStandardItemModel();
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("Seq"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("User"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("Time"));
    table_view->setModel(model);
    int width = table_view->width();
    table_view->setColumnWidth(0, width/3-1);    //设置列的宽度
    table_view->setColumnWidth(1, width/3);
    table_view->setColumnWidth(2, width/3);
    table_view->verticalHeader()->hide();
    return model;
}

void
set_datalist(QTableView* table_view, vector<User*> user_list)
{
    QStandardItemModel  *model = new QStandardItemModel();
    model->setColumnCount(4);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("Seq"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("User"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("Start"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("Service"));

    QStandardItem* item = 0;
    int seq, start_time, last_time;
    char user_type;
    for (vector<User*>::iterator it = user_list.begin(); it != user_list.end(); ++it) {
        seq = (*it)->get_seq();
        start_time = (*it)->get_s_time();
        last_time = (*it)->get_last_time();
        user_type = (*it)->get_user_type();
        item = new QStandardItem(QString("%1").arg(seq));
        item->setTextAlignment(Qt::AlignCenter);
        item->setEditable(false);
        model->setItem(seq-1,0,item);
        item = new QStandardItem(QString("%1").arg(user_type));
        item->setTextAlignment(Qt::AlignCenter);
        item->setEditable(false);
        model->setItem(seq-1,1,item);
        item = new QStandardItem(QString("%1").arg(start_time));
        item->setTextAlignment(Qt::AlignCenter);
        item->setEditable(false);
        model->setItem(seq-1,2,item);
        item = new QStandardItem(QString("%1").arg(last_time));
        item->setTextAlignment(Qt::AlignCenter);
        item->setEditable(false);
        model->setItem(seq-1,3,item);
    }

    table_view->verticalHeader()->hide();
    table_view->setModel(model);
    int width = table_view->width();
    table_view->setColumnWidth(0, width/4-1);    //设置列的宽度
    table_view->setColumnWidth(1, width/4);
    table_view->setColumnWidth(2, width/4);
    table_view->setColumnWidth(3, width/4);
}

void
Main_view::set_changedview(const User* user_ptr, const string status, const int time)
{
    if (status != "ready") {
        remove_item_from_tableview(user_ptr->get_seq(), get_status(status), this);
    }
    add_item_to_tableview(user_ptr->get_seq(), user_ptr->get_user_type(), time, get_status(status), this);

}

void
Main_view::set_buttonstatus(bool status)
{
    if (restart_flag)
        ui->start_pushButton->setText("Restart");
    if (status)
        ui->start_pushButton->setEnabled(true);
    else
        ui->start_pushButton->setDisabled(true);
}

int
get_status(string status)
{
    return status_list.find(status)->second;
}

void
add_item_to_tableview(int seq, char user_type, int time, int status, Main_view* mainview)
{
    QStandardItemModel  *model = mainview->model_list->at(status);
    QTableView* table_view = mainview->tableview_list->at(status);
    int line_count = model->rowCount();
    QStandardItem *item1,*item2,*item3;
    item1 = new QStandardItem(QString("%1").arg(seq));
    item1->setTextAlignment(Qt::AlignCenter);
    item1->setEditable(false);
    item2 = new QStandardItem(QString("%1").arg(user_type));
    item2->setTextAlignment(Qt::AlignCenter);
    item2->setEditable(false);
    item3 = new QStandardItem(QString("%1").arg(time));
    item3->setTextAlignment(Qt::AlignCenter);
    item3->setEditable(false);

    QList<QStandardItem*> list;
    list << item1 << item2 << item3;
    model->insertRow(line_count,list);
    table_view->setModel(model);
}

void
remove_item_from_tableview(int seq, int status, Main_view* mainview)
{
    QStandardItemModel  *model = mainview->model_list->at(status-1);
    QTableView* table_view = mainview->tableview_list->at(status-1);    //remove previous tableview
    int line_count = model->rowCount();
    QModelIndex index;
    QVariant data;
    for (int i = 0; i < line_count; ++i) {
        index = model->index(i,0);
        data = model->data(index);
        if (data.toInt() == seq) {

            model->removeRow(i);
            break;
        }
    }
    table_view->setModel(model);
}

void
Main_view::update_time()
{
    ui->time_label->setText(QString::number(now));
}

void
Main_view::clear()
{
    QStandardItemModel  *model = model_list->at(3);
    int line_count = model->rowCount();
    for(int i = 0; i < line_count; ++i) {
        model->removeRow(0);
    }
    ui->finished_tableView->setModel(model);
}

