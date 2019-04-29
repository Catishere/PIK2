#ifndef COMPANY_SERVICE_H
#define COMPANY_SERVICE_H

#include "record.h"
#include "macros.h"
#include "linked_list.h"

int record_compare (const record *rec1, const record *rec2);
int add_company(linked_list *records, const record *rec);
int add_record(linked_list *records, const record *rec);
int get_records(linked_list *records);
int update_record(linked_list *records, const record *rec_old,
                  const record *rec_new);
int save(linked_list *records);
int create_company_file(const record *rec);

#endif // COMPANY_SERVICE_H
