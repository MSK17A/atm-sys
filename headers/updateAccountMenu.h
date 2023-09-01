#ifndef UPDATEACCOUNTMENU_H
#define UPDATEACCOUNTMENU_H

#include "../src/sqlite/sqlite3.h"
#include "user_struct.h"

void updateAccountMenu(sqlite3 *db, User *user);

#endif