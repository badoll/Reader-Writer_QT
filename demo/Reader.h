#ifndef READER_H
#define READER_H

#include <thread>
#include <ctime>
#include "User.h"
#include "global_var.h"

using namespace std;
class Reader: public User
{
    Q_OBJECT
public:
    Reader() = default;
    Reader(int num, char type, int stime, int ltime): User(num, type, stime, ltime) { }
    ~Reader(){}
    void start();           // start thread.
    void read();
};



#endif // READER_H

