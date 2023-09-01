#ifndef HELPER_FUNCS_H
#define HELPER_FUNCS_H

#include <stdio.h>

/* Replace a substring with a string */
char *string_replace(char *source, size_t sourceSize, char *substring,
                     char *with);

#endif