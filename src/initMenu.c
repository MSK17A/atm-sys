#include "addUserMenu.h"
#include "loginMenu.h"
#include "sql_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initMenu(sqlite3 *db) {
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
      /*loginMenu(u->name, u->password);
      if (strcmp(u->password, getPassword(*u)) == 0)
      {
          printf("\n\nPassword Match!");
      }
      else
      {
          printf("\nWrong password!! or User Name\n");
          exit(1);
      }
      r = 1;
      break;
      */
		loginMenu(db);
      exit(1);
      break;
    case 2:
      // student TODO : add your **Registration** function
      // here
      addUserMenu(db);
      // add_user(db, "Users", "rada", 665);
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
