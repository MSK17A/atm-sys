#ifndef sql_operation_h
#define sql_operation_h

#include <sqlite3.h>
#include <user_struct.h>

void sql_insert(sqlite3 *db, char *Table_name, char *Columnes_names,
                char *Values);
void add_user(sqlite3 *db, User *user);
void add_account(sqlite3 *db, User *user);
int get_user_id(sqlite3 *db, User *user);
char *get_user_pass(sqlite3 *db, User *user);

#endif