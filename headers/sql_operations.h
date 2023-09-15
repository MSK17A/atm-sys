#ifndef sql_operation_h
#define sql_operation_h

#include <sqlite/sqlite3.h>
#include <user_struct.h>

void sql_insert(sqlite3 *db, char *Table_name, char *Columnes_names,
                char *Values);
char *get_user_pass(sqlite3 *db, User *user);

#endif