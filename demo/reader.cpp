#include "Reader.h"

void Reader::start()
{
    std::thread t(&Reader::read,this);
    t.detach();
}

void Reader::read()
{
    chg_status(this,"ready",now);
    time_t start_time;
    start_time = time(0);
    while (true)
        if (time(0) - start_time >= get_s_time())
            break;
    chg_status(this,"ask",now);
    r_mux.lock();
    if (reader_num == 0) {
        rw_mux.lock();
    }
    reader_num++;
    r_mux.unlock();
    start_time = time(0);
    chg_status(this,"use",now);

    while (true) {
        if (time(0) - start_time >= get_last_time()) {
            r_mux.lock();
            reader_num--;
            r_mux.unlock();
            chg_status(this,"finish",now);
            if (reader_num == 0) {
                rw_mux.unlock();
            }
            break;
        }
    }
    user_num--;
    if (user_num == 0) {
        emit end_sig();
        cout << "All users finished." << endl;
    }
}

