#include <stdlib.h>

typedef struct element{
    int key;
} element;

element *initialize_element(int key);

void set_element_key(element *e, int key);

int get_element_key(element *e);

int compare_element(element *a, element *b);