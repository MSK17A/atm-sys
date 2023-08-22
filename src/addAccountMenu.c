#include "../headers/addUserMenu.h"
#include "../headers/sql_operations.h"
#include "../headers/user_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int validate_name(char *name);
int validate_Account_type(char *acc_type);
int validate_Country(char *Country);
int validate_Phone(char *Phone);
int validate_Balance(double Balance);

void addAccountMenu(__unused sqlite3 *db, User *user) {
  char Name[30];
  char Account_type[8];
  char Country[4];
  char Phone[10];
  double Balance;

  system("clear");
  printf("\n\n\t\t======= Account Registeration =======\n");
  printf("\n\t\tName :\n");
  scanf("%s", Name);
  if (!validate_name(Name)) {
    printf("Name must be less than 30 charachters!\n");
    sleep(2);
    addAccountMenu(db, user);
  }

  printf("\n\t\tAccount type: \n");
  scanf("%s", Account_type);

  printf("\n\t\tCountry: \n");
  scanf("%s", Country);

  printf("\n\t\tPhone: \n");
  scanf("%s", Phone);

  printf("\n\t\tBalance: \n");
  scanf("%lf", &Balance);

  printf("oi brookk!");
  char *data[] = {Name, Account_type, Country, Phone};
  selected_record_construction(user, data, Balance);
  add_account(db, user);
}

int validate_name(char *name) {
  if (strlen(name) >= 30) {
    return 0;
  } else {
    return 1;
  }
}