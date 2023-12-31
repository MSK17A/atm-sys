#include <addUserMenu.h>
#include <atm_operations.h>
#include <helper_funcs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <user_struct.h>

void addUserMenu(sqlite3 *db, User *user) {
  char user_input[30];

  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\tUser name :\n");
  scanf("%s", user_input);
  strcpy(user->userName, user_input);

  printf("\n\t\tEnter password :\n");
  scanf("%s", user_input);
  strcpy(user->userPass, user_input);

  add_user(db, user);
  logged_in_user_construction(user, user->userName, user->userPass);
  pressEnterToContinue();
  /*printf("%s%s%s%s", "username: ", user->userName,
         " password: ", user->userPass);*/
}