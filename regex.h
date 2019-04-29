#ifndef REGEX_H
#define REGEX_H

#include <stdlib.h>
#include <ctype.h>

int match_digits(char *pointer, size_t count);
int match_letters(char *pointer, size_t count);
int match_alphanum(char *pointer, size_t count);
int match_char(char *pointer, size_t count, char ch);

#endif // REGEX_H
