#ifndef ATM_OPERATIONS_H
#define ATM_OPERATIONS_H

#include <sqlite3.h>
#include <user_struct.h>

int add_user(sqlite3 *db, User *user);
int get_user_id(sqlite3 *db, User *user);
int add_account(sqlite3 *db, User *user);
int update_account(sqlite3 *db, User *user, int account_number);
char **get_accounts_ids(sqlite3 *db, User *user);

#endif