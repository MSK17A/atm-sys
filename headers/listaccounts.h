#ifndef LISTACCOUNTS_H
#define LISTACCOUNTS_H

#include <sqlite/sqlite3.h>
#include <user_struct.h>

void listaccounts(sqlite3 *db, User *user);

#endif