#include "key.h"
#include "stdlib.h"

typedef struct element{
    key *key;
} element;

element *inizialize_element(key *);

void set_element_key(element *, key *);

int get_element_key(element *);

int compare_element(element *, element *);

void delete_element(element *);