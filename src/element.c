#include "element.h"

element *initialize_element(int k){
    element *tmp = (element *) malloc(sizeof(element));
    tmp -> key = k;

    return tmp;
}

void set_element_key(element *element, int key){
    element -> key = key;
}

int get_element_key(element *element){
    return element -> key;
}

int compare_element(element *a, element *b){
    if(a -> key == b -> key){
        return 0;
    }else if(a -> key > b -> key){
        return 1;
    }else{
        return -1;
    }
}