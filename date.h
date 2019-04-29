#ifndef DATE_H
#define DATE_H

#include <string.h>
#include <stdlib.h>

struct date
{
    int day;
    int month;
    int year;
    int sum;
};

typedef struct date date;

date construct_date(int year, int month, int day);
date parse_date(char *date_str);
int compare_dates(date d1, date d2);
int compare_string_dates(char *date1, char *date2);
int is_between(char *date_, char *from, char *to);

#endif // DATE_H
