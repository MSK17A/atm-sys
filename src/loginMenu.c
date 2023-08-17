#include "../headers/sql_operations.h"
#include "sqlite/sqlite3.h"
#include "../headers/user_struct.h"

void loginMenu(sqlite3 *db, User *user) {
  char user_input[30];

  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\tUser name :\n");
  printf("%s", user->userName);
  scanf("%s", user_input);
  strcpy(user->userName, user_input);
  if (get_user_id(db, *user) == -1)
    exit(1);

  printf("\n\t\tEnter password :\n");
  scanf("%s", user_input);
  strcpy(user->userPass, user_input);
}