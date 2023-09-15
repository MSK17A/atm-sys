#define _GNU_SOURCE
#include <helper_funcs.h>
#include <sql_operations.h>
#include <sqlite/sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <user_struct.h>

static int callback(__attribute__((unused)) void *NotUsed, int argc, char **argv,
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
__attribute__((unused)) static int get_id_callback(void *data, __attribute__((unused)) int argc, char **argv,
                           __attribute__((unused)) char **azColName) {
  FoundUser *user = (FoundUser *)data;
  // printf("argc: %d, argv: %s, %s", argc, argv[0], "\n");
  user->user_id = atoi(argv[0]);

  strncpy(user->userName, argv[0], sizeof(user->userName));
  return 0;
}

static int get_pass_callback(void *data, int argc __attribute__((unused)), char **argv,
                            char **azColName __attribute__((unused))) {
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
  char *sql = "INSERT INTO {table_name} ({columns_names}) VALUES ({values});";

  // old = [Hi {name} THERE] // 10
  // NEW = calloc(10 + n)
  // memcpy(new, 3,  old)
  // memcpy(new, n, arg1)
  // memcpy(new, 6, old_mn_wra)
  // new[n] = '\0'

  /* Create SQL statement */
  string_replace(&sql, 200, "{table_name}", Table_name);
  string_replace(&sql, 200, "{columns_names}", Columnes_names);
  string_replace(&sql, 200, "{values}", Values);

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Records created successfully\n");
  }
  // free(sql);
}

/* Returns user pass */
char *get_user_pass(sqlite3 *db, User *user) {
  char *zErrMsg = 0;
  int rc;
  char *sql = NULL;
  __attribute__((unused)) char *oper = "INSERT INTO ";
  __attribute__((unused)) const char *data = "Callback function called";

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