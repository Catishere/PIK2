#include "company_service.h"

int add_record(linked_list *records, const record *rec)
{
    return push(records, *rec);
}

int save(linked_list *records)
{
    FILE *file = fopen(FAKE_DB_FILE, "wb");

    ASSERT_WRONG(file, NULL, "fopen");

    records->current = records->first;
    do
    {
        if (records->current != NULL)
            fwrite(&records->current->value, sizeof(record), 1, file);
    } while (next(records));

    fclose(file);
    return 0;
}

int create_company_file(const record *rec)
{
    FILE *file = fopen(rec->tax_num, "w");
    ASSERT_WRONG(file, NULL, "fopen");

    char string_rec[SERIAL_REC_SIZE];
    serialize_record(rec, string_rec);

    size_t rev = fwrite(string_rec, 1, strlen(string_rec), file);
    ASSERT_TRUE(rev, SERIAL_REC_SIZE, "fwrite")

    fclose(file);
    return 0;
}

int get_records(linked_list *records)
{
    fclose(fopen(FAKE_DB_FILE, "wb"));
    FILE *file = fopen(FAKE_DB_FILE, "rb");
    ASSERT_WRONG(file, NULL, "fopen")

    construct_list(records);

    record rec;
    while (fread(&rec, sizeof(record), 1, file) == 1)
        push(records, rec);

    fclose(file);
    return 0;
}

int update_record(linked_list *records, const record *rec_old,
                  const record *rec_new)
{
    node_t *node = find(records, rec_old);
    if (node != NULL)
        node->value = *rec_new;
    else
        return 1;
    return 0;
}

//int update_by_tax_num(linked_list *records, const record *rec_old,
//                            char *tax_num)
//{
//    node_t *node = find_by_tax_num(records, tax_num);
//    if (node != NULL)
//        node->value = *rec_new;
//    else
//        return 1;
//    return 0;
//}

int add_company(linked_list *records, const record *rec)
{
    add_record(records, rec);
    create_company_file(rec);
    return 0;
}
