#include <helper_funcs.h>
#include <stdlib.h>
#include <string.h>

/* Replace a substring with a string */
char *string_replace(char **source, size_t sourceSize, char *substring,
                     char *with) {

  char *buffer = calloc(1, strlen(*source) + 200);
  strcpy(buffer, *source);

  char *substring_source = strstr(buffer, substring);

  if (substring_source == NULL) {
    return NULL;
  }

  if (sourceSize < strlen(buffer) + strlen(with) - strlen(substring) + 1) {
    printf("string_replace: buffer size is too small");
    return NULL;
  }
  memmove(substring_source + strlen(with), substring_source + strlen(substring),
          strlen(substring_source) - strlen(substring) + 1);

  memcpy(substring_source, with, strlen(with));

  *source = buffer;
  return substring_source;
}

void stdin_flush() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    // Do nothing; just read and discard characters
  }
}

void pressEnterToContinue() {
  stdin_flush();
  printf("Press ENTER to continue...");
  while (getchar() != '\n') {
  }
}