#include "menu.h"

int main()
{
    linked_list list;
    get_records(&list);

    start_menu(&list);
    return 0;
}
