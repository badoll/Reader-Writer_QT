#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H
/**
 * avoid header file include nested too deeply.
 */
#include <mutex>

using namespace std;
extern mutex r_mux, rw_mux, chg_status_mux;
extern int reader_num, user_num;
extern time_t origin_time;
extern time_t now;
extern bool restart_flag;
#endif // GLOBAL_VAR_H
