#include "../headers/addUserMenu.h"
#include "../headers/sql_operations.h"
#include "../headers/user_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addAccountMenu(sqlite3 *db, User *user) {
  char user_input[30];
  double u2;

  system("clear");
  printf("\n\n\t\t======= Account Registeration =======\n");
  printf("\n\t\tName :\n");
  scanf("%s", user_input);
  strncpy(user->records->name, user_input, 7);
  printf("\n\t\tAccount type: \n");
  scanf("%s", user_input);
  strncpy(user->records->acc_type, user_input, 7);
  printf("\n\t\tCountry: \n");
  scanf("%s", user_input);
  strncpy(user->records->country, user_input, 3);
  printf("\n\t\tPhone: \n");
  scanf("%s", user_input);
  strncpy(user->records->phone, user_input, 9);
  printf("\n\t\tBalance: \n");
  scanf("%lf", &u2);
  user->records->balance = u2;

  user->records->user_id = user->userID;
  add_account(db, user);
}