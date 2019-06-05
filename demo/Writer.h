#ifndef WRITER_H
#define WRITER_H

#include <thread>
#include <ctime>
#include "User.h"
#include "global_var.h"

using namespace std;

class Writer: public User
{
    Q_OBJECT
public:
    Writer() = default;
    Writer(int num, char type, int stime, int ltime): User(num, type, stime, ltime) {}
    ~Writer() {}
    void start();           // start thread.
    void write();
};


#endif // WRITER_H
