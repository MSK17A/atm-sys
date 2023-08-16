#ifndef user_struct_h
#define user_struct_h

typedef struct User User;

struct User {
  char userName[30], userPass[30];
  int accountId;
};

#endif
