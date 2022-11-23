#include "element.h"

element *inizialize_element(key *k){
    element *tmp = (element *) malloc(sizeof(element));
    tmp -> key = k;

    return tmp;
}

void set_element_key(element *element, key *new_key){
    element -> key = new_key;
}

int get_element_key(element *element){
    return get_key(element -> key);
}

int compare_element(element *element1, element *elemnent2){
    return compare_key(element1 -> key, elemnent2 -> key);
}

void delete_element(element *element){
    delete_key(element -> key);
    free(element);
}