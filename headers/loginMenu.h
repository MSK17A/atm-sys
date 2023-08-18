#ifndef loginMenu_h
#define loginMenu_h

#include "user_struct.h"
#include "../src/sqlite/sqlite3.h"

int loginMenu(sqlite3 *db, User *user);
#endif