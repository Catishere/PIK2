#ifndef MAIN_H
#define MAIN_H

#define TAX_NUM_LEN 13
#define NAME_LEN 40
#define DATE_LEN 10

struct record
{
    char tax_num[DATE_LEN + 1];
    char name[NAME_LEN + 1];
    double five_year_profit[5];
    char date[DATE_LEN];
};

typedef struct record record;

#endif // MAIN_H
