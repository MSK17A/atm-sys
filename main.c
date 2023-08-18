#include "headers/initMenu.h"
#include "headers/mainMenu.h"
#include "headers/sql_operations.h"
#include "headers/user_struct.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  User user;

  /* Opening the database */
  rc = sqlite3_open("test.db", &db);

  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return (0);
  } else {
    fprintf(stderr, "Opened database successfully\n");
  }

  initMenu(db, &user);

  sqlite3_close(db);
  return 0;
}