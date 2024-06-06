#ifndef DB_UTILS_H_INCLUDED
#define DB_UTILS_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <sqlite3.h>

#include "system_utils.h"

bool storeEvent(const char* event_text);

#endif // DB_UTILS_H_INCLUDED
