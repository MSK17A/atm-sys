#ifndef sql_operation_h
#define sql_operation_h

#include "sql_operations.c"

void sql_insert(sqlite3 *db, char *Table_name, char *Columnes_names,
                char *Values);
void add_user(sqlite3 *db, char *user_name, char *user_pass,
              unsigned int account_id);
void add_account(sqlite3 *db, char *user_name, char *user_pass,
                 unsigned int account_id);
void get_user(User user);

#endif