#include "Writer.h"

void Writer::start()
{
    std::thread t(&Writer::write,this);
    t.detach();
}

void Writer::write()
{
    chg_status(this,"ready",now);
    time_t start_time;
    start_time = time(0);
    while (true)
        if (time(0) - start_time >= get_s_time())
            break;
    chg_status(this,"ask",now);
    rw_mux.lock();
    start_time = time(0);
    chg_status(this,"use",now);
    while (true) {
        if (time(0) - start_time >= get_last_time()) {
            rw_mux.unlock();
            chg_status(this,"finish",now);
            break;
        }
    }
    user_num--;
    if (user_num == 0) {
        emit end_sig();
        cout << "All users finished." << endl;
    }
}
