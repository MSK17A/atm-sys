#ifndef addUserMenu_h
#define addUserMenu_h

#include "../src/addUserMenu.c"
#include "user_struct.h"

void addUserMenu(sqlite3 *db, User *user);

#endif