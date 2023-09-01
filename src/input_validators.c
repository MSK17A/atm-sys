/* Input validators */
#include "../headers/input_validators.h"
#include <ctype.h>
#include <string.h>

int validate_name(char *name) {
  if (strlen(name) >= 30) {
    return 0;
  } else {
    return 1;
  }
}

int validate_Account_type(char *acc_type) {
  char *accs[] = {"savings", "fixed"};
  for (int i = 0; i < 3; i++) {
    if (strcmp(acc_type, accs[i]) == 0)
      return 1;
  }
  return 0;
}
int validate_Country(char *Country) {
  int in_size = arr_length(Country);
  if (in_size > 4) {
    return 0;
  }
  for (int i = 0; i < in_size; i++) {
    if (!isalpha(Country[i])) {
      return 0;
    }
  }
  return 1;
}
int validate_Phone(char __unused *Phone) { return 1; }
int validate_Balance(double __unused Balance) { return 1; }

int arr_length(char arr[]) {
  int i;
  int count = 0;
  for (i = 0; arr[i] != '\0'; i++) {
    count++;
  }
  return count;
}