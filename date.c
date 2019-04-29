#include "date.h"

date construct_date(int year, int month, int day)
{
    date d;
    d.day = day;
    d.month = month;
    d.year = year;
    d.sum = year * 10000 + month * 100 + day;
    return d;
}

date parse_date(char *date_str)
{
    char day[3];
    char month[3];
    char year[5];

    strncpy(year, date_str, 4);
    year[4] = '\0';
    strncpy(month, date_str + 5, 2);
    month[2] = '\0';
    strncpy(day, date_str + 8, 2);
    day[2] = '\0';

    return construct_date(atoi(year), atoi(month), atoi(day));
}

int compare_dates(date d1, date d2)
{
    if (d1.sum > d2.sum)
        return 1;
    else if (d1.sum < d2.sum)
        return -1;
    else
        return 0;
}

int is_between(char *date_, char *from, char *to)
{
    if (compare_string_dates(date_, from) > 0
        && compare_string_dates(date_, to) < 0)
        return 1;
    else
        return 0;
}

int compare_string_dates(char *date1, char *date2)
{
    return compare_dates(parse_date(date1), parse_date(date2));
}
