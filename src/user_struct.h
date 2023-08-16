#ifndef user_struct_h
#define user_struct_h

typedef struct User User;

struct User {
  char *userName, *userPass;
  int accountId;
};

#endif
