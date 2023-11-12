#include <stdlib.h>
#include <string.h>

struct linked_list{
    struct linked_list *next;

    int key; 
    void *value;
};

struct linked_list *linked_list_initialize(int key, void *value, size_t value_len);

struct linked_list *linked_list_search(struct linked_list *head, int key);

int linked_list_insert(struct linked_list *head, int key, void *value, size_t value_len);

int linked_list_delete(struct linked_list *head, int key);