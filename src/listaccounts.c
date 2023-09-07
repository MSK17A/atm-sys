#include <atm_operations.h>
#include <ctype.h>
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
  char **ids = get_accounts_ids(db, user);
  while (start_menu) {
    start_menu = 0;

    system("clear");
    printf("\n\n\t\t======= Update Account Information =======\n");
    printf("\n\t\tAccounts ids :\n");

    for (int i = 0; i < (int)(sizeof(ids) / sizeof(int)); i++) {
      printf("%s\n", ids[i]);
    }
  }
}