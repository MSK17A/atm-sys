#include "../headers/addAccountMenu.h"
#include "../headers/user_struct.h"
#include "sqlite/sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mainMenu(sqlite3 *db, User *user) {
  int option;
  system("clear");
  printf("\n\n\t\t======= ATM =======\n\n");
  printf("\n\t\t-->> Feel free to choose one of the options below <<--\n");
  printf("\n\t\t[1]- Create a new account\n");
  printf("\n\t\t[2]- Update account information\n");
  printf("\n\t\t[3]- Check accounts\n");
  printf("\n\t\t[4]- Check list of owned account\n");
  printf("\n\t\t[5]- Make Transaction\n");
  printf("\n\t\t[6]- Remove existing account\n");
  printf("\n\t\t[7]- Transfer ownership\n");
  printf("\n\t\t[8]- Exit\n");
  scanf("%d", &option);

  switch (option) {
  case 1:
    // createNewAcc(u);
    break;
  case 2:
    // student TODO : add your **Update account information** function
    // here
    addAccountMenu(db, user);
    break;
  case 3:
    // student TODO : add your **Check the details of existing accounts**
    // function here
    break;
  case 4:
    // checkAllAccounts(u);
    break;
  case 5:
    // student TODO : add your **Make transaction** function
    // here
    break;
  case 6:
    // student TODO : add your **Remove existing account** function
    // here
    break;
  case 7:
    // student TODO : add your **Transfer owner** function
    // here
    break;
  case 8:
    exit(1);
    break;
  default:
    printf("Invalid operation!\n");
  }
};