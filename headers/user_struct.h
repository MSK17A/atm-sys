#ifndef user_struct_h
#define user_struct_h

typedef struct {
  int account_id;
  double balance;
  int user_id;
  char acc_type[8], country[4], acc_num[30], phone[10], date[11];
} Record;

typedef struct {
  char userName[30], userPass[30];
  int userID;
  Record *records;
} User;

void logged_in_user_construction(User *user, char *User_name, char *Password);
void selected_record_construction(User *user, char *data[], double balance);

typedef struct {
  char *account_number, country[4], phone_number[10], *type_of_account;
  double balance;
} User_Account;

#endif
