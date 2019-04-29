#include "regex.h"

int match_digits(char *pointer, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (!isdigit(pointer[i]))
            return 0;
    }
    return 1;
}

int match_letters(char *pointer, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (!isalpha(pointer[i]))
            return 0;
    }
    return 1;
}

int match_char(char *pointer, size_t count, char ch)
{
    for (size_t i = 0; i < count; i++)
    {
        if (pointer[i] != ch)
            return 0;
    }
    return 1;
}

int match_alphanum(char *pointer, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (!isalnum(pointer[i]) && !isspace(pointer[i]))
            return 0;
    }
    return 1;
}
