#include "sql_operations.c"

void sql_insert(sqlite3 *db, char *Table_name, char *Columnes_names,
                char *Values);
void add_user(sqlite3 *db, char *user_name, char *user_pass,
              unsigned int account_id);