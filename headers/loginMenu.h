#ifndef loginMenu_h
#define loginMenu_h

#include <sqlite3.h>
#include <user_struct.h>

int loginMenu(sqlite3 *db, User *user);
#endif