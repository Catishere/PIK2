#include "menu.h"

int add_opt(linked_list *list)
{
    system("cls");
    record rec;
    do {
        record_input_form(&rec);
    } while (!validate(&rec));
    display_record(&rec);
    push(list, rec);

    return 0;
}

int save_opt(linked_list *list)
{
    system("cls");
    if (save(list))
        return 1;

    printf("Saved!");
    getch();

    return 0;
}

int verify_question(void)
{
    printf("\nAre you sure? yes / no: ");
    char answer[4];
    scanf("%4s", answer);
    return !strcmp(answer, "yes");
}

node_t * show_info_dialog(linked_list *list)
{
    system("cls");
    char tax_number[TAX_NUM_LEN];
    INPUT_FIELD("Find by tax number", tax_number, 13)

    node_t *node;
    if ((node = find_by_tax_num(list, tax_number)) == NULL){
        printf("\nRecord not found!\n");
        getch();
        return NULL;
    }
    display_record(&node->value);
    return node;
}

int update_opt(linked_list *list)
{
    node_t * node;
    if ((node = show_info_dialog(list)) == NULL)
        return 0;

    record new_rec;
    record_input_form(&new_rec);
    record tmp = node->value;
    record_cpy(&tmp, &new_rec);
    display_record(&tmp);

    if (verify_question())
        node->value = tmp;

    return 0;
}

int five_year_profit_opt(linked_list *list)
{
    char date1[11];
    char date2[11];
    INPUT_FIELD("Date 1", date1, 10);
    INPUT_FIELD("Date 2", date2, 10);
    linked_list filtered;
    linked_list *fil_p = &filtered;
    construct_list(&filtered);
    if (date_filter(&filtered, date1, date2, list) > 0) {
        FILTER(fil_p, display_record(&fil_p->current->value));
    }
    else
    {
        printf("Nothing found between %s and %s", date1, date2);
        getch();
    }
    return 0;
}

int get_info_opt(linked_list *list)
{
    show_info_dialog(list);
    return 0;
}

int handle_choice(int menu_index, linked_list *list)
{
    system("cls");

    switch (menu_index)
    {
    case 5:
        return EXIT_CODE;
    case 4:
        save_opt(list);
        break;
    case 3:
        get_info_opt(list);
        break;
    case 2:
        five_year_profit_opt(list);
        break;
    case 1:
        update_opt(list);
        break;
    case 0:
        add_opt(list);
        break;
    }
    return 0;
}

int start_menu(linked_list *list)
{
    int menu_index = 0;
    while (1)
    {
        system("cls");

        printf("----COMPANY-MENU----\n");
        printf("Add\t");
        printf((menu_index == 0) ? "<\n" : "\n");
        printf("Update\t");
        printf((menu_index == 1) ? "<\n" : "\n");
        printf("5 year profit\t");
        printf((menu_index == 2) ? "<\n" : "\n");
        printf("Get Info\t");
        printf((menu_index == 3) ? "<\n" : "\n");
        printf("Save\t");
        printf((menu_index == 4) ? "<\n" : "\n");
        printf("Quit\t");
        printf((menu_index == 5) ? "<\n" : "\n");

        int ch = getch();
        if (ch == 's')
        {
            menu_index++;
            menu_index %= 6;
        }
        else if (ch == 'w')
        {
            menu_index--;
            if (menu_index < 0)
                menu_index += 6;
        }
        else if (ch == '\r')
        {
            if (handle_choice(menu_index, list) == EXIT_CODE)
                return 0;
        }
    }
}

size_t readline(char *line, size_t size)
{
    if (size > 49)
        return 0;

    size_t i = 0;
    while (1)
    {
        if (i >= size)
        {
            line[i] = '\0';
            while ((fgetc(stdin)) != '\n');
            return i;
        }

        int c = fgetc(stdin);
        if (c == '\0')
        {
            while ((fgetc(stdin)) != '\n');
            break;
        }

        if (c == '\n')
        {
            if (i == 0)
                continue;
            line[i] = '\0';
            break;
        }
        line[i] = (char) c;
        i++;
    }

    return i;
}

int record_input_form(record *rec)
{
    INPUT_FIELD("Tax Num", rec->tax_num, 13)
    INPUT_FIELD("Name", rec->name, 40)
    INPUT_FIELD("Date (YYYY.MM.DD)", rec->date, 10)

    printf("5 Year profits: ");
    for (int i = 0; i < 5; i++)
        scanf("%lf", &rec->profits[i]);

    return 0;
}
