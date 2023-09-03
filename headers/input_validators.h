/* Input validators */
#ifndef ADDACCOUNTMENU_H
#define ADDACCOUNTMENU_H

int validate_account_number(char *name);
int validate_Account_type(char *acc_type);
int validate_Country(char *Country);
int validate_Phone(char *Phone);
int validate_Balance(double Balance);
int arr_length(char arr[]);

#endif