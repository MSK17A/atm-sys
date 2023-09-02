#include <user_struct.h>
#include <sql_operations.h>
#include <stdio.h>
#include <string.h>

void logged_in_user_construction(User *user, char *User_name, char *Password) {
  strcpy(user->userName, User_name);
  strcpy(user->userPass, Password);
}

/* Updates the state of the selected records, (used to update records in the
 * database)
 * Inputs:
    user: user struct (logged in user)
    data: An array of [name, account_type, country, phone]
    balance: Amount in the account to be configured.
 */
void selected_record_construction(User *user, char *data[], double balance) {

  strcpy(user->records->acc_num, data[0]);
  strcpy(user->records->acc_type, data[1]);
  strcpy(user->records->country, data[2]);
  strcpy(user->records->phone, data[3]);
  user->records->balance = balance;
  user->records->user_id = user->userID;
}