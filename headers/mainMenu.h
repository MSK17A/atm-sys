#ifndef mainMenu_h
#define mainMenu_h

#include "user_struct.h"
#include "../src/sqlite/sqlite3.h"

void mainMenu(sqlite3 *db, User *user);

#endif