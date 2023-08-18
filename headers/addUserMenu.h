#ifndef ADDUSERMENU_H
#define ADDUSERMENU_H

#include "../src/sqlite/sqlite3.h"
#include "user_struct.h"

void addUserMenu(sqlite3 *db, User *user);

#endif