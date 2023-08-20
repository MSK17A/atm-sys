#ifndef user_struct_h
#define user_struct_h

typedef struct {
  int account_id;
  double balance;
  int user_id;
  char acc_type[7], country[3], name[30], phone[9];
} Record;

typedef struct {
  char userName[30], userPass[30];
  int userID;
  Record *records;
} User;

void logged_in_user_construction(User *user, char *User_name, char *Password);
void selected_record_construction(User *user, char *data[], double balance);

#endif
