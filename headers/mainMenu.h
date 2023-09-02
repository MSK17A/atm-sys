#ifndef mainMenu_h
#define mainMenu_h

#include <sqlite3.h>
#include <user_struct.h>

void mainMenu(sqlite3 *db, User *user);

#endif