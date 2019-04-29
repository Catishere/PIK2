#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "company_service.h"

#define EXIT_CODE -1

size_t readline(char *line, size_t size);
node_t * show_info_dialog(linked_list *list);
int verify_question(void);
int record_input_form(record *rec);
int handle_choice(int menu_index, linked_list *list);
int start_menu(linked_list *list);
int add_opt(linked_list *list);
int save_opt(linked_list *list);
int update_opt(linked_list *list);
int five_year_profit_opt(linked_list *list);
int get_info_opt(linked_list *list);

#endif // MENU_H
