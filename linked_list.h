#include "element.h"

typedef struct linked_list{
    element *elem;
    struct linked_list *next;
} linked_list;

linked_list *inzialize_linked_list(element *);

void add_node(linked_list **, element *);

int delete_node(linked_list **, key *);

int delete_node_from_index(linked_list **, int);

void print_all_list(linked_list *);

bool list_include(linked_list *, key *);

void swap_node(linked_list **, int, int);

int node_count(linked_list *);

linked_list *get_node_by_index(linked_list *, int);

int get_max_key(linked_list *);

int get_min_key(linked_list *);

int get_node_information(linked_list *, int);

int partition(linked_list **, int, int);

void quicksort(linked_list **, int, int);