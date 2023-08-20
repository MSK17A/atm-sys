#include "../headers/addUserMenu.h"
#include "../headers/sql_operations.h"
#include "../headers/user_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addAccountMenu(__unused sqlite3 *db, User *user) {
  char Name[30];
  char Account_type[7];
  char Country[3];
  char Phone[9];
  double Balance;

  system("clear");
  printf("\n\n\t\t======= Account Registeration =======\n");
  printf("\n\t\tName :\n");
  scanf("%s", Name);

  printf("\n\t\tAccount type: \n");
  scanf("%s", Account_type);

  printf("\n\t\tCountry: \n");
  scanf("%s", Country);

  printf("\n\t\tPhone: \n");
  scanf("%s", Phone);

  printf("\n\t\tBalance: \n");
  scanf("%lf", &Balance);

  char *data[] = {Name, Account_type, Country, Phone};
  selected_record_construction(user, data, Balance);
  add_account(db, user);
}