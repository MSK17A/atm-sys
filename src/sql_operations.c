#include "sqlite/sqlite3.h"
#include "string.h"
#include "user_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

void sql_insert(sqlite3 *db, char *Table_name, char *Columnes_names,
                char *Values) {
  char *zErrMsg = 0;
  int rc;
  char *sql;
  char *oper = "INSERT INTO ";

  /* Create SQL statement */
  sprintf(sql, "%s%s%s%s%s%s%s%s", oper, Table_name, " ", Columnes_names, " ",
          "VALUES", Values, ";");
  /*sql = "INSERT INTO Users (userName,passWord,accountId) "
        "VALUES ('Paul', 'fds', 4433 ); ";*/

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Records created successfully\n");
  }
}

void add_user(sqlite3 *db, char *user_name, char *user_pass) {
  char *user, *pass, *acc_id, *Values;

  user = (char *)malloc(strlen(user_name) + 3); // +3 for surrounding ''
  pass = (char *)malloc(strlen(user_pass) + 3); // +3 for surrounding ''
  Values = (char *)malloc(strlen(user_name) + strlen(user_pass) + 12 + 5 + 9);
  sprintf(user, "%s%s%s", "'", user_name, "'"); // Surround with ' '
  sprintf(pass, "%s%s%s", "'", user_pass, "'"); // Surround with ' '
  sprintf(Values, "%s%s%s%s%s", "(", user, ",", pass, ")");
  fprintf(stdout, "%s", Values);

  sql_insert(db, "Users", "(userName,passWord)", Values);
}

void add_account(sqlite3 *db, char *user_name, char *user_pass,
                 unsigned int account_id) {

                 }

void get_user(User user) {

}