#ifndef user_struct_h
#define user_struct_h

typedef struct {
  int account_id;
  double balance;
  int user_id;
  char *acc_type, *country, *name, *phone;
} Record;

typedef struct {
  char userName[30], userPass[30];
  int userID;
  Record records[];
} User;

void user_construction(User *user);

#endif
