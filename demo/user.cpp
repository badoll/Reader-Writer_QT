#include "User.h"

void
User::chg_status(const User* user_ptr, const string status, const int time)
{
    chg_status_mux.lock();
    emit chg_status_sig(user_ptr,status,time);
    chg_status_mux.unlock();
}
