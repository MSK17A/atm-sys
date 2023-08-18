#ifndef sql_operation_h
#define sql_operation_h

#include "../src/sql_operations.c"

void sql_insert(sqlite3 *db, char *Table_name, char *Columnes_names,
                char *Values);
void add_user(sqlite3 *db, char *user_name, char *user_pass);
void add_account(sqlite3 *db, char *user_name, char *user_pass,
                 unsigned int account_id);
int get_user_id(sqlite3 *db, User *user);
char *get_user_pass(sqlite3 *db, User *user);

#endif