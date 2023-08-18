#include "../headers/mainMenu.h"
#include "../headers/sql_operations.h"
#include "../headers/user_struct.h"
#include "sqlite/sqlite3.h"

void loginMenu(sqlite3 *db, User *user) {
  char user_input[30];

  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\tUser name :\n");
  scanf("%s", user_input);

  /* Stores the username inside user struct */
  strcpy(user->userName, user_input);
  /* Check if the id is found or exit the program if it wasn't found */
  if (get_user_id(db, user) == -1)
    exit(1);

  const char *userPassword = get_user_pass(db, user);
  printf("\n\t\tEnter password :\n");
  scanf("%s", user_input);
  /* Stores the password inside user struct */
  strcpy(user->userPass, user_input);

  /* Compares the password in the database with the provided password, if it is
   * match then enter the mainMenu as a user */
  if (strcmp(userPassword, user->userPass) == 0) {
    mainMenu(db, user);
  } else {
    /* Or else ask to retry or exit */
    printf("Wrong Pass\n");
    printf("Retry? (Y/N): ");
    scanf("%s", user_input);
    if (strcmp(user_input, "Y") == 0) {
      loginMenu(db, user);
    } else {
      exit(1);
    }
  }
}