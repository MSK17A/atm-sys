#include "../headers/addUserMenu.h"
#include "../headers/sql_operations.h"
#include "../headers/user_struct.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Input validators */
int validate_name(char *name);
int validate_Account_type(char *acc_type);
int validate_Country(char *Country);
int validate_Phone(char *Phone);
int validate_Balance(double Balance);

int arr_length(char arr[]) {
  int i;
  int count = 0;
  for (i = 0; arr[i] != '\0'; i++) {
    count++;
  }
  return count;
}

/* This will render the add account form window */
void addAccountMenu(__unused sqlite3 *db, User *user) {
  int start_menu = 1;
  char Name[30];
  char Account_type[8];
  char Country[4];
  char Phone[10];
  double Balance;
  while (start_menu) {
    start_menu = 0;

    system("clear");
    printf("\n\n\t\t======= Account Registeration =======\n");
    printf("\n\t\tName :\n");
    scanf("%s", Name);
    if (!validate_name(Name)) {
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

int validate_Account_type(char *acc_type) {
  char *accs[] = {"savings", "fixed"};
  for (int i = 0; i < 3; i++) {
    if (strcmp(acc_type, accs[i]) == 0)
      return 1;
  }
  return 0;
}
int validate_Country(char *Country) {
  int in_size = arr_length(Country);
  if (in_size > 4) {
    return 0;
  }
  for (int i = 0; i < in_size; i++) {
    if (!isalpha(Country[i])) {
      return 0;
    }
  }
  return 1;
}
int validate_Phone(char __unused *Phone) { return 1; }
int validate_Balance(double __unused Balance) { return 1; }