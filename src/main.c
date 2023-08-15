#include "initMenu.h"
#include "mainMenu.h"
#include "sql_operations.h"

int main(int argc, char *argv[]) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  char *sql;

  rc = sqlite3_open("test.db", &db);

  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return (0);
  } else {
    fprintf(stderr, "Opened database successfully\n");
  }

  /*sql_insert(db, "Users", "(userName,passWord,accountId)",
             "('rats','bata',21)");*/

  add_user(db, "Users", "rada", 665);

  sqlite3_close(db);
  return 0;
}