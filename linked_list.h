#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "record.h"
#include "macros.h"

struct node_t
{
    record value;
    int index;
    struct node_t *next;
};
typedef struct node_t node_t;

struct linked_list
{
    node_t *last;
    node_t *current;
    node_t *first;
    int size;
};
typedef struct linked_list linked_list;

void construct_list(linked_list *list);
void destruct_list(linked_list *list);
node_t * next(linked_list *list);
void pop_first(linked_list *list);
int push(linked_list *record_list, record rec);
void pop_current(linked_list *record_list, node_t *prev);
int date_filter(linked_list *result, char *from, char *to, linked_list *list);
node_t * find_by_tax_num(linked_list *record_list, char *tax_num);
node_t * find(linked_list *record_list, const record *rec);
void remove_record(linked_list *record_list, const record *rec);

#endif // LINKED_LIST_H
