#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <mutex>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include "User.h"
#include "Reader.h"
#include "Writer.h"
#include "Main_view.h"
#include "global_var.h"

class Controller : public QObject
{
    Q_OBJECT
    vector<User*>* user_list;
    Main_view* mainview;
    QTimer *timer;
public:
    Controller();
    ~Controller();
    void show_initialview(string path);
    void clear();
    void do_connect();
public slots:
    void start();
    void chg_status(const User*,const string,const int);
    void update_time();
    void end();
};

#endif // CONTROLLER_H
