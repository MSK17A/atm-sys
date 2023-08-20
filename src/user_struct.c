#include "../headers/user_struct.h"
#include <stdio.h>
#include <string.h>

void logged_in_user_construction(User *user, char *User_name, char *Password) {
  strcpy(user->userName, User_name);
  strcpy(user->userPass, Password);
}

void selected_record_construction(User *user, char *data[], double balance) {

  strcpy(user->records->name, data[0]);
  strcpy(user->records->acc_type, data[1]);
  strcpy(user->records->country, data[2]);
  strcpy(user->records->phone, data[3]);
  user->records->balance = balance;
}