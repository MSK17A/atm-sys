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