#include "element.h"

typedef struct linked_list{
    element *elem;
    struct linked_list *next;
} linked_list;

linked_list *inzialize_linked_list(element *elem);

void add_node(linked_list *list, element *elem);

linked_list *delete_node(linked_list *list, key *chiave);

linked_list *delete_node_from_index(linked_list *list, int index);

void print_all_list(linked_list *list);

bool list_include(linked_list *list, key *key);