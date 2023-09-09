#include <atm_operations.h>
#include <ctype.h>
#include <helper_funcs.h>
#include <input_validators.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <updateAccountMenu.h>
#include <user_struct.h>

/* This will render the add account form window */
void updateAccountMenu(__unused sqlite3 *db, __unused User *user) {
  int start_menu = 1;
  char acc_num[30];
  __unused char Country[4];
  __unused char Phone[10];

  while (start_menu) {
    start_menu = 0;

    system("clear");
    printf("\n\n\t\t======= Update Account Information =======\n");
    printf("\n\t\tAccount number :\n");
    scanf("%s", acc_num);
    if (!validate_account_number(acc_num)) {
      printf("Account number must be less than 30 charachters!\n");
      sleep(2);
      start_menu = 1;
      continue;
    }

    printf("\n\t\tPhone :\n");
    scanf("%s", Phone);

    printf("\n\t\tCountry :\n");
    scanf("%s", Country);

    /* Update phone and country in the user records buffer */
    strcpy(user->records->phone, Phone);
    strcpy(user->records->country, Country);
    update_account(db, user, atoi(acc_num));
  }

  stdin_flush();
  printf("Press ENTER to continue...");
  while (getchar() != '\n') {
  }
}