#include "sql_operations.h"
#include "user_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addUserMenu(sqlite3 *db) {
  char user_input[30];
  User user;

  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\tUser name :\n");
  scanf("%s", user_input);
  strcpy(user.userName, user_input);

  printf("\n\t\tEnter password :\n");
  scanf("%s", user_input);
  strcpy(user.userPass, user_input);

  add_user(db, user.userName, user.userPass);
  printf("%s%s%s%s", "username: ", user.userName, " password: ", user.userPass);
}