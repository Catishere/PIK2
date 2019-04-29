#include "record.h"

int record_compare (const record *rec1, const record *rec2)
{
    if (!strcmp(rec1->tax_num, rec2->tax_num)
        && !strcmp(rec1->name, rec2->name)
        && !strcmp(rec1->date, rec2->date)
        && !memcmp(rec1->profits, rec2->profits, 40))
        return 1;
    else
        return 0;
}

int record_cpy(record *dest, const record *src)
{
    if (src->tax_num[0] != '$')
        strcpy(dest->tax_num, src->tax_num);
    if (src->name[0] != '$')
        strcpy(dest->name, src->name);
    if (src->date[0] != '$')
        strcpy(dest->date, src->date);
    if (sizeof(src->profits) == 40)
        memcpy(dest->profits, src->profits, 40);
    return 0;
}

void serialize_record(const record *rec, char *serialized)
{
    const char *format_string = "Tax num: %s\n"
                                 "Name: %s\n"
                                 "Profit (past 5 years): %lf %lf %lf %lf %lf\n"
                                 "Date: %s\n";
    sprintf(serialized, format_string, rec->tax_num, rec->name,
                                rec->profits[0], rec->profits[1],
                                rec->profits[2], rec->profits[3],
                                rec->profits[4], rec->date);
}

int match_record_date(char *date)
{
    if (match_digits(date, 4)
        && match_char(date + 4, 1, '.')
        && match_digits(date + 5, 2)
        && match_char(date + 7, 1, '.')
        && match_digits(date + 5, 2))
    {
        return 1;
    }
    return 0;
}


void display_record(const record *rec)
{
    char serialized[SERIAL_REC_SIZE];
    serialize_record(rec, serialized);
    printf("\n--RECORD--\n%s--END--\n\n", serialized);
    getche();
}


int validate(record *rec)
{
    if (!match_digits(rec->tax_num, 13) || strlen(rec->tax_num) == 0)
        return 0;

    size_t name_len = strlen(rec->name);
    if (name_len == 0 || !match_alphanum(rec->name, name_len))
        return 0;

    if (strlen(rec->date) != 10 && !match_record_date(rec->date))
        return 0;

    return 1;
}
