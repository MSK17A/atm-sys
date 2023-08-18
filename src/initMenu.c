#include "../headers/addUserMenu.h"
#include "../headers/loginMenu.h"
#include "../headers/sql_operations.h"
#include "../headers/user_struct.h"
#include "../headers/mainMenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initMenu(sqlite3 *db, User *user) {
  int r = 0;
  int option;
  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\t-->> Feel free to login / register :\n");
  printf("\n\t\t[1]- login\n");
  printf("\n\t\t[2]- register\n");
  printf("\n\t\t[3]- exit\n");
  while (!r) {
    scanf("%d", &option);
    switch (option) {
    case 1:
      /* If user logged in successfully let him enters mainMenu */
      if (loginMenu(db, user) == 1) {
        mainMenu(db, user);
      } else {
        exit(1);
      }
      break;
    case 2:
      // student TODO : add your **Registration** function
      // here
      addUserMenu(db, user);
      r = 1;
      break;
    case 3:
      exit(1);
      break;
    default:
      printf("Insert a valid operation!\n");
    }
  }
};
