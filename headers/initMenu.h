#ifndef initMenu_h
#define initMenu_h

#include <sqlite/sqlite3.h>
#include <user_struct.h>

void initMenu(sqlite3 *db, User *user);

#endif