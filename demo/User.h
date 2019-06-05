#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <QObject>
#include "global_var.h"


class User: public QObject
{
    Q_OBJECT
    int seq = 0;
    char user_type;
    int s_time = 0;
    int last_time = 0;

public:
    User() = default;
    User(int num, char type, int stime, int ltime): seq(num),user_type(type), s_time(stime), last_time(ltime) {}
    int get_seq() const {return seq;}
    char get_user_type() const {return user_type;}
    int get_s_time() const {return s_time;}
    int get_last_time() const {return last_time;}

    virtual ~User(){}
    virtual void start() {}
    void chg_status(const User*,const string,const int);
signals:
    void chg_status_sig(const User*,const string,const int);
    void end_sig();
};


#endif // USER_H
