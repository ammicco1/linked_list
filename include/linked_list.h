#include <stdio.h>
#include "element.h"

typedef struct linked_list{
    element *element;
    struct linked_list *next;
} linked_list;

linked_list *initialize_linked_list(element *element);

void insert_node(linked_list **list, element *element, int index);

void append_node(linked_list **list, element *element);

void insert_head_node(linked_list **list, element *element);

int delete_node(linked_list **list, int index);

int delete_first_node(linked_list **list);

int delete_last_node(linked_list **list);

int print_list(linked_list *list);

int list_include(linked_list *list, int key);

int size(linked_list *list);

linked_list *get_node(linked_list *list, int index);

linked_list *reverse(linked_list **list, linked_list *prev);