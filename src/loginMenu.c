#include "sqlite/sqlite3.h"
#include "user_struct.h"
#include "sql_operations.h"

void loginMenu(sqlite3 *db) {
  User user;
  get_user(db, user);
}