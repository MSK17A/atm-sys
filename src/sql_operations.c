#include "../headers/sql_operations.h"
#include "../headers/user_struct.h"
#include "sqlite/sqlite3.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int callback(__unused void *NotUsed, int argc, char **argv,
                    char **azColName) {
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
  char *userPass;
} FoundUser;

/* This callback is used to retrive the data from the database and store them
 * inside a struct */
static int get_id_callback(void *data, __unused int argc, char **argv,
                           __unused char **azColName) {
  FoundUser *user = (FoundUser *)data;
  // printf("argc: %d, argv: %s, %s", argc, argv[0], "\n");
  user->user_id = atoi(argv[0]);

  strncpy(user->userName, argv[0], sizeof(user->userName));
  return 0;
}

static int get_pass_callback(void *data, __unused int argc, char **argv,
                             __unused char **azColName) {
  FoundUser *user = (FoundUser *)data;
  // printf("argc: %d, argv: %s, %s", argc, argv[0], "\n");
  asprintf(&user->userPass, "%s", argv[0]);

  strncpy(user->userName, argv[0], sizeof(user->userName));
  return 0;
}

void sql_insert(sqlite3 *db, char *Table_name, char *Columnes_names,
                char *Values) {
  char *zErrMsg = 0;
  int rc;
  char *sql = NULL;

  /* Create SQL statement */
  asprintf(&sql, "%s%s%s%s%s%s%s%s", "INSERT INTO ", Table_name, " ",
           Columnes_names, " ", "VALUES", Values, ";");

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Records created successfully\n");
  }
  free(sql);
}

void add_user(sqlite3 *db, User *user) {
  char *Values;

  asprintf(&Values, "%s%s%s%s%s", "('", user->userName, "','", user->userPass,
           "')");

  sql_insert(db, "Users", "(userName,userPass)", Values);
  user->userID = get_user_id(db, user);
  free(Values);
}

void add_account(__unused sqlite3 *db, User *user) {
  char *Values;
  /*printf("Acc name:  %s Balance: %lf\n", user->records->name,
         user->records->balance);*/
  asprintf(&Values, "%s%d%s%s%s%s%s%s%s%s%s%lf%s", "(", user->records->user_id,
           ",'", user->records->acc_type, "','", user->records->country, "','",
           user->records->name, "','", user->records->phone, "',",
           user->records->balance, ")");
  sql_insert(db, "Records", "(user_id,acc_type,country,account_number,phone,balance)",
             Values);
  free(Values);
}

/* This function will search for user and returns its ID */
int get_user_id(sqlite3 *db, User *user) {
  char *zErrMsg = 0;
  int rc;
  char *sql = NULL;
  __unused const char *data = "Callback function called";

  /* Create SQL statement */
  asprintf(&sql, "%s%s%s%s%s",
           "SELECT user_id FROM Users WHERE userName = ", "'", user->userName,
           "'", ";");

  /* Execute SQL statement */
  FoundUser fUser;    // Found user struct
  fUser.user_id = -1; // Init value for user_id
  rc = sqlite3_exec(db, sql, get_id_callback, &fUser, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }

  /* If user wasn't found */
  if (fUser.user_id == -1) {
    fprintf(stdout, "User not found!\n");
    return -1;
  }
  return fUser.user_id;
}

/* Returns user pass */
char *get_user_pass(sqlite3 *db, User *user) {
  char *zErrMsg = 0;
  int rc;
  char *sql = NULL;
  __unused char *oper = "INSERT INTO ";
  __unused const char *data = "Callback function called";

  /* Create SQL statement */
  asprintf(&sql, "%s%s%s%s%s",
           "SELECT userPass FROM Users WHERE userName = ", "'", user->userName,
           "'", ";");

  /* Execute SQL statement */
  FoundUser fUser;       // Found user struct
  fUser.userPass = "-1"; // Init value for userPass
  rc = sqlite3_exec(db, sql, get_pass_callback, &fUser, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }

  return fUser.userPass;
}