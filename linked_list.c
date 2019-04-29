#include "linked_list.h"

void construct_list(linked_list *list)
{
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    list->current = NULL;
}

void destruct_list(linked_list *list)
{
    node_t *tmp = list->first;
    FILTER(list,
       free(tmp);
       tmp = list->current;
    )
}


void pop_first(linked_list *list)
{
    node_t *tmp = list->first;
    list->first = list->first->next;
    free(tmp);
    list->size--;
}

node_t * next(linked_list *list)
{
    if (list->current->next == NULL)
        return NULL;

    list->current = list->current->next;
    return list->current;
}

int push(linked_list *list, record rec)
{
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    ASSERT_WRONG(new_node, NULL, "malloc")

    if (list->size == 0)
        list->first = new_node;
    else
        list->last->next = new_node;

    new_node->value = rec;
    new_node->next = NULL;
    new_node->index = list->size;

    list->last = new_node;
    list->size++;

    return 0;
}

node_t * find_by_tax_num(linked_list *record_list, char *tax_num)
{
    if (record_list->size == 0)
        return NULL;

    FILTER(record_list,
       if (!strcmp(record_list->current->value.tax_num, tax_num))
           return record_list->current;
    )
    return NULL;
}

int date_filter(linked_list *result, char *from, char *to, linked_list *list)
{
    int i = 0;
    FILTER(list,
       if (is_between(list->current->value.date, from, to))
        {
           push(result, list->current->value);
           i++;
        }
    )
    return i;
}

node_t * find(linked_list *record_list, const record *rec)
{
    FILTER(record_list,
        if (record_compare(&record_list->current->value, rec))
            return record_list->current;
    )
    return NULL;
}

void pop_current(linked_list *record_list, node_t *prev)
{
    node_t *next = record_list->current->next;

    if (prev != NULL && next != NULL)
        prev->next = next;
    else if (prev == NULL)
        record_list->first = next;
    else if (next == NULL)
    {
        prev->next = NULL;
        record_list->last = prev;
    }
    else {
        record_list->first = NULL;
        record_list->last = NULL;
    }

    free(record_list->current);
    record_list->size--;
}

void remove_record(linked_list *record_list, const record *rec)
{
    if (record_list->size == 0)
        return;

    record_list->current = record_list->first;
    node_t *prev = NULL;

    do
    {
        if (record_compare(&record_list->current->value, rec))
        {
            pop_current(record_list, prev);
            break;
        }
        else
            prev = record_list->current;

    } while (next(record_list) != NULL);
}
