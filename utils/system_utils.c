#include "system_utils.h"

const char* getCurrentTime(void){
    time_t current_time;
    current_time = time(NULL);
    const char* str_time = ctime(&current_time);
    return str_time;
}
