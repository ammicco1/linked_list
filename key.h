#include <stdlib.h>
#include <stdbool.h>

typedef struct key{
    int key;
} key;

key *inzialize_key(int);

void set_key(key *, int);

int get_key(key *);

int compare_key(key *, key *);

void delete_key(key *);