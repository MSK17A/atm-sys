#include <atm_operations.h>
#include <sql_operations.h>
#include <stdio.h>
#include <stdlib.h>

int add_user(sqlite3 *db, User *user) {
  int rc;
  // Define the SQL INSERT statement with specific columns
  const char *insertSQL =
      "INSERT INTO Users (userName, userPass) VALUES (?, ?)";

  // Prepare the SQL statement
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, 0);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return (0);
  }

  // Bind values to the parameters in the prepared statement
  rc = sqlite3_bind_text(stmt, 1, user->userName, -1, SQLITE_STATIC);
  rc = sqlite3_bind_text(stmt, 2, user->userPass, -1, SQLITE_STATIC);

  // Execute the SQL statement
  rc = sqlite3_step(stmt);

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Insert failed: %s\n", sqlite3_errmsg(db));
  } else {
    fprintf(stdout, "Data inserted successfully\n");
  }

  // Finalize and close the statement
  sqlite3_finalize(stmt);

  user->userID = get_user_id(db, user);

  return 0;
}

int get_user_id(sqlite3 *db, User *user) {
  int rc;
  int id = -1;
  // Define the SQL SELECT statement with a WHERE clause
  const char *selectSQL = "SELECT user_id FROM Users WHERE userName = ?";

  // Prepare the SQL statement
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, 0);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return (0);
  }

  // Bind a value to the parameter in the prepared statement
  rc = sqlite3_bind_text(stmt, 1, user->userName, -1, SQLITE_STATIC);

  // Execute the SQL statement and fetch results
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    id = sqlite3_column_int(stmt, 0);
  }

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Select failed: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    return -1;
  }

  // Finalize and close the statement
  sqlite3_finalize(stmt);
  return id;
}

int add_account(__unused sqlite3 *db, User *user) {
  int rc;
  // Define the SQL INSERT statement with specific columns
  const char *insertSQL =
      "INSERT INTO Records (user_id,acc_type,country,acc_num,phone,balance) "
      "VALUES (?, ?, ?, ?, ?, ?)";

  // Prepare the SQL statement
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, 0);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return (0);
  }

  // Bind values to the parameters in the prepared statement
  rc = sqlite3_bind_int(stmt, 1, user->records->user_id);
  rc = sqlite3_bind_text(stmt, 2, user->records->acc_type, -1, SQLITE_STATIC);
  rc = sqlite3_bind_text(stmt, 3, user->records->country, -1, SQLITE_STATIC);
  rc = sqlite3_bind_text(stmt, 4, user->records->acc_num, -1, SQLITE_STATIC);
  rc = sqlite3_bind_text(stmt, 5, user->records->phone, -1, SQLITE_STATIC);
  rc = sqlite3_bind_double(stmt, 6, user->records->balance);

  // Execute the SQL statement
  rc = sqlite3_step(stmt);

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Insert failed: %s\n", sqlite3_errmsg(db));
  } else {
    fprintf(stdout, "Data inserted successfully\n");
  }

  // Finalize and close the statement
  sqlite3_finalize(stmt);

  return 0;
}

int update_account(sqlite3 *db, User *user, int account_number) {
  int rc;
  // Define the SQL INSERT statement with specific columns
  // need to verify user_id first before updating anything
  const char *updateSQL = "UPDATE Records SET phone = ?, country = ? WHERE "
                          "acc_num = ? AND user_id = ?";
  // Prepare the SQL statement
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, updateSQL, -1, &stmt, 0);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return (0);
  }

  // Bind values to the parameters in the prepared statement
  rc = sqlite3_bind_text(stmt, 1, user->records->phone, -1, SQLITE_STATIC);
  rc = sqlite3_bind_text(stmt, 2, user->records->country, -1, SQLITE_STATIC);
  rc = sqlite3_bind_int(stmt, 3, account_number);
  rc = sqlite3_bind_int(stmt, 4, user->records->user_id);
  // Execute the SQL statement
  rc = sqlite3_step(stmt);

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Insert failed: %s\n", sqlite3_errmsg(db));
  } else {
    fprintf(stdout, "Data inserted successfully\n");
  }

  // Finalize and close the statement
  sqlite3_finalize(stmt);

  return 0;
}

char **get_accounts_ids(sqlite3 *db, User *user) {
  int rc;
  char **ids = malloc(1);
  // Define the SQL SELECT statement with a WHERE clause
  const char *selectSQL = "SELECT acc_num FROM Records WHERE user_id = ?";

  // Prepare the SQL statement
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, 0);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return (0);
  }

  // Bind a value to the parameter in the prepared statement
  rc = sqlite3_bind_int(stmt, 1, user->userID);

  // Execute the SQL statement and fetch results
  int count = 0;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    asprintf(&ids[count], "%s", sqlite3_column_text(stmt, 0));
    count++;
  }

  // Add NULL after the end of the array to indicate end of array
  asprintf(&ids[count], "%s", "NULL");

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Select failed: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    return NULL;
  }

  // Finalize and close the statement
  sqlite3_finalize(stmt);
  return ids;
}

User_Account *get_accounts_list(sqlite3 *db, User *user) {
  int rc;
  /* Variables to be encapsulated */
  User_Account *user_accounts = malloc(sizeof(User_Account));

  // Define the SQL SELECT statement with a WHERE clause
  const char *selectSQL = "SELECT * FROM Records WHERE user_id = ?";

  // Prepare the SQL statement
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, 0);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return (0);
  }

  // Bind a value to the parameter in the prepared statement
  rc = sqlite3_bind_int(stmt, 1, user->userID);

  // Execute the SQL statement and fetch results
  int count = 0;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    user_accounts = realloc(user_accounts, sizeof(User_Account));
    asprintf(&user_accounts[count].account_number, "%s",
             sqlite3_column_text(stmt, 5));

    count++;
  }

  // Add NULL after the end of the array to indicate end of array
  user_accounts = realloc(user_accounts, sizeof(User_Account));
  asprintf(&user_accounts[count].account_number, "%s", "NULL");

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Select failed: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    return NULL;
  }

  // Finalize and close the statement
  sqlite3_finalize(stmt);
  return user_accounts;
}