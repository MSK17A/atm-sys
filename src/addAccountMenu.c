#include <addUserMenu.h>
#include <atm_operations.h>
#include <ctype.h>
#include <input_validators.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <user_struct.h>

/* This will render the add account form window */
void addAccountMenu(sqlite3 *db, User *user) {
  int start_menu = 1;
  char acc_num[30];
  char Account_type[8];
  char Country[4];
  char Phone[10];
  double Balance;
  while (start_menu) {
    start_menu = 0;

    system("clear");
    printf("\n\n\t\t======= Account Registeration =======\n");
    printf("\n\t\tName :\n");
    scanf("%s", acc_num);
    if (!validate_account_number(acc_num)) {
      printf("Name must be less than 30 charachters!\n");
      sleep(2);
      start_menu = 1;
      continue;
    }

    printf("\n\t\tAccount type: \n");
    scanf("%s", Account_type);
    if (!validate_Account_type(Account_type)) {
      printf("select either (savings, fixed)\n");
      sleep(2);
      start_menu = 1;
      continue;
    }

    printf("\n\t\tCountry: \n");
    scanf("%s", Country);
    if (!validate_Country(Country)) {
      printf("Write 3 letters country code\n");
      sleep(2);
      start_menu = 1;
      continue;
    }

    printf("\n\t\tPhone: \n");
    scanf("%s", Phone);
    if (!validate_Phone(Phone)) {
      printf("invalid phone number\n");
      sleep(2);
      start_menu = 1;
      continue;
    }

    printf("\n\t\tBalance: \n");
    scanf("%lf", &Balance);
    if (!validate_Balance(Balance)) {
      printf("BAAKAA!!!\n");
      sleep(2);
      start_menu = 1;
      continue;
    }
  }
  char *data[] = {acc_num, Account_type, Country, Phone};
  selected_record_construction(user, data, Balance);
  add_account(db, user);
}
