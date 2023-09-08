#include <atm_operations.h>
#include <ctype.h>
#include <helper_funcs.h>
#include <input_validators.h>
#include <listaccounts.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <user_struct.h>

/* This will render the add account form window */
void listaccounts(sqlite3 *db, User *user) {
  int start_menu = 1;
  // char **ids = get_accounts_ids(db, user);
  User_Account *user_accounts = get_accounts_list(db, user);
  while (start_menu) {
    start_menu = 0;

    system("clear");
    printf("\n\n\t\t======= Update Account Information =======\n");
    printf("\t\tAccounts for user: %s\n", user->userName);

    for (int i = 0; strcmp(user_accounts[i].account_number, "NULL"); i++) {
      printf("Account number: %s\n", user_accounts[i].account_number);
      printf("Type: %s\n", user_accounts[i].type_of_account);

      /* Free the memory */
      free(user_accounts[i].account_number);
      free(user_accounts[i].type_of_account);
    }

    stdin_flush();
    printf("Press ENTER to continue...");
    while (getchar() != '\n') {
    }
  }

  free(user_accounts);
}