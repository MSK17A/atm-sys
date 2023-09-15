#include <initMenu.h>
#include <mainMenu.h>
#include <sql_operations.h>
#include <stdio.h>
#include <user_struct.h>

int main() {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  User user;

  /* Opening the database */
  rc = sqlite3_open("atm.db", &db);

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