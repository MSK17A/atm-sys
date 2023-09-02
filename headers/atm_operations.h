#ifndef ATM_OPERATIONS_H
#define ATM_OPERATIONS_H

#include <sqlite3.h>
#include <user_struct.h>

int add_user(sqlite3 *db, User *user);

#endif