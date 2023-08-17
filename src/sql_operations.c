#include "sqlite/sqlite3.h"
#include "string.h"
#include "../headers/user_struct.h"
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

typedef struct {
  int user_id;
  char userName[45];
} FoundUser;

/* This callback is used to retrive that data from the database and store them
 * inside a struct */
static int get_callback(void *data, int argc, char **argv, char **azColName) {
  printf("1\n");
  FoundUser *user = (FoundUser *)data;
  printf("2\n");
  printf("argc: %d, %s", argc, argv[0]);
  user->user_id = atoi(argv[0]);
  printf("3\n");

  strncpy(user->userName, argv[0], sizeof(user->userName));
  printf("4\n");
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

  asprintf(&user, "%s%s%s", "'", user_name, "'"); // Surround with ' '
  asprintf(&pass, "%s%s%s", "'", user_pass, "'"); // Surround with ' '
  asprintf(&Values, "%s%s%s%s%s", "(", user, ",", pass, ")");
  fprintf(stdout, "%s", Values);

  sql_insert(db, "Users", "(userName,userPass)", Values);
  free(user);
  free(pass);
  free(Values);
}

void add_account(sqlite3 *db, char *user_name, char *user_pass,
                 unsigned int account_id) {}

/* This function will search for user and returns its ID */
int get_user_id(sqlite3 *db, User user) {
  char *zErrMsg = 0;
  int rc;
  char *sql = NULL;
  char *oper = "INSERT INTO ";
  const char *data = "Callback function called";

  /* Create SQL statement */
  asprintf(&sql, "%s%s%s%s%s",
           "SELECT user_id FROM Users WHERE userName = ", "'", user.userName,
           "'", ";");

  /* Execute SQL statement */
  FoundUser fUser;    // Found user struct
  fUser.user_id = -1; // Init value for user_id
  rc = sqlite3_exec(db, sql, get_callback, &fUser, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Operation done successfully\n");
  }
  sqlite3_close(db);

  /* If user wasn't found */
  if (fUser.user_id == -1) {
    fprintf(stdout, "User not found!");
    return -1;
  }
  fprintf(stdout, "FOUND!!!");
  return fUser.user_id;
}