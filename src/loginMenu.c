#include "../headers/mainMenu.h"
#include "../headers/sql_operations.h"
#include "../headers/user_struct.h"
#include "sqlite/sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Returns 1 when user logged in successfully, or 0 when use enters wrong
 * credentials */
int loginMenu(sqlite3 *db, User *user) {
  char User_Name[30];
  char Password[30];
  char user_input[2];

  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\tUser name :\n");
  scanf("%s", User_Name);

  printf("\n\t\tEnter password :\n");
  scanf("%s", Password);

  logged_in_user_construction(user, User_Name, Password);
  const char *userPassword = get_user_pass(db, user);

  /* Check if the id is found or exit the program if it wasn't found */
  if (get_user_id(db, user) == -1)
    exit(1);

  /* Compares the password in the database with the provided password, if it is
   * match then enter the mainMenu as a user */
  if (strcmp(userPassword, user->userPass) == 0) {
    // mainMenu(db, user);
    return 1;
  } else {
    /* Or else ask to retry or exit */
    printf("Wrong Pass\n");
    printf("Retry? (Y/N): ");
    scanf("%s", user_input);
    if (strcmp(user_input, "Y") == 0) {
      return loginMenu(db, user);
    } else {
      return 0;
    }
  }
  return 0;
}