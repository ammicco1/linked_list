#include "key.h"

key *inzialize_key(int k){
    key *tmp = (key *) malloc(sizeof(key));
    tmp -> key = k;

    return tmp;
}

void set_key(key *key, int new_value){
    key -> key = new_value;
}

int get_key(key *key){
    return key -> key;
}

int compare_key(key *key1, key *key2){
    if(key1 -> key > key2 -> key){
        return 1;
    }else if(key1 -> key < key2 -> key){
        return -1;
    }else{
        return 0;
    }
}

void delete_key(key *k){
    free(k);
}
