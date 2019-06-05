#include "Controller.h"
using namespace std;
mutex r_mux;
mutex rw_mux;
mutex chg_status_mux;
time_t origin_time;
time_t now;
int reader_num;
int user_num;
bool restart_flag = false;

Controller::Controller():
    user_list(new vector<User*>()),
    mainview(new Main_view()),
    timer(new QTimer(this))
{
    /*
     * C++在new时的初始化的规律可能为：对于有构造函数的类，
     * 不论有没有括号，都用构造函数进行初始化；
     * 如果没有构造函数，则不加括号的new只分配内存空间，
     * 不进行内存的初始化，而加了括号的new会在分配内存的同时初始化为0。
     */
}

Controller::~Controller()
{
    delete mainview;
    mainview = NULL;
    for (vector<User*>::iterator it = user_list->begin(); it != user_list->end(); ++it) {
        delete *it;
        *it = NULL;
    }
    delete user_list;
    user_list = NULL;
    delete timer;
    timer = NULL;
}

void
Controller::show_initialview(string path)
{
    ifstream data_in(path);
    if (!data_in.is_open())
        mainview->set_errorview();
    else {
        string data;
        while(getline(data_in,data)) {
            user_num++;
            istringstream s(data);
            int seq, start_time, last_time;
            char user_type;
            s >> seq >> user_type >> start_time >> last_time;
            if (user_type == 'R') {
                Reader *r = new Reader(seq, user_type, start_time, last_time);
                user_list->push_back(r);
            } else {
                Writer *w = new Writer(seq, user_type, start_time, last_time);
                user_list->push_back(w);
            }
        }
        do_connect();   //connect signals and slots.
        mainview->set_initialview(*user_list);
    }
    mainview->show();
}

void
Controller::start()
{
    mainview->set_buttonstatus(false);
    if (restart_flag)
        clear();
    cout << "start!!" << endl;
    timer->start(1000);
    now = 0;
    origin_time = time(0);
    for (vector<User*>::iterator it = user_list->begin(); it != user_list->end(); ++it) {
        (*it)->start();
//        cout << it->get_seq() << " " << it->get_user_type() << " " << it->get_s_time() << " " << it->get_last_time() << endl;
    }
}

void
Controller::chg_status(const User* user_ptr, const string status, const int time)
{
    mainview->set_changedview(user_ptr,status,time);
}

void
Controller::update_time()
{
    now = time(0) - origin_time;
    mainview->update_time();
}

void
Controller::end()
{
    restart_flag = true;
    timer->stop();
    mainview->set_buttonstatus(true);
}

void
Controller::clear()
{
    user_num = user_list->size();
    mainview->clear();
}

void
Controller::do_connect()
{
    //connect(sender, signal, receiver, slot);

    timer->setTimerType(Qt::PreciseTimer);
    connect(timer, &QTimer::timeout, this, &Controller::update_time);

    qRegisterMetaType<string>("string");        //connect中传递了非qt库中类型参数string,需要注册string

    QObject::connect(mainview->get_start_pushButton(), &QPushButton::clicked, this, &Controller::start);

    for (vector<User*>::iterator it = user_list->begin(); it != user_list->end(); ++it) {
        QObject::connect(*it, &User::chg_status_sig, this, &Controller::chg_status);
        QObject::connect(*it, &User::end_sig, this, &Controller::end);
    }
}
