#ifndef RECORD_H
#define RECORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "regex.h"
#include "date.h"

#define TAX_NUM_LEN 14
#define NAME_LEN 41
#define DATE_LEN 11
#define SERIAL_REC_SIZE 230

struct record
{
    char tax_num[TAX_NUM_LEN];
    char name[NAME_LEN];
    double profits[5];
    char date[DATE_LEN];
};

typedef struct record record;

void serialize_record(const record *rec, char *serialized);
void display_record(const record *rec);
int record_compare(const record *rec1, const record *rec2);
int record_cpy(record *dest, const record *src);
int match_record_date(char *date);
int validate(record *rec);


#endif // RECORD_H
