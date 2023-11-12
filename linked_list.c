#include "linked_list.h"

struct linked_list *linked_list_initialize(int key, void *value, size_t value_len){
    struct linked_list *list = (struct linked_list *) malloc(sizeof(struct linked_list));

    list -> next = NULL;
    list -> key = key;
    
    list -> value = malloc(value_len);
    memcpy(list -> value, value, value_len);

    return list;
}

struct linked_list *linked_list_search(struct linked_list *head, int key){
    if(!head || head -> key == key){
        return head;
    }else{
        return head -> next ? linked_list_search(head -> next, key) : NULL;
    }
}

int linked_list_insert(struct linked_list *head, int key, void *value, size_t value_len){
    struct linked_list *tmp = head, *new = (struct linked_list *) malloc(sizeof(struct linked_list));

    new -> next = NULL;
    new -> key = key;

    new -> value = malloc(value_len);
    memcpy(new -> value, value, value_len);

    while(tmp && tmp -> next){
        tmp = tmp -> next;
    } 

    tmp -> next = new;

    return 0;
}

int linked_list_delete(struct linked_list *head, int key){
    struct linked_list *tmp = head, *tmp2 = NULL;

    if(tmp -> key == key && tmp -> next){
        *head = *tmp -> next;

        return 0;
    }else if(tmp -> key == key && !tmp -> next){
        return 1;
    }

    while(tmp -> next && tmp -> next -> key != key){
        tmp = tmp -> next;
    }

    if(tmp -> next && tmp -> next -> next){
        tmp -> next = tmp -> next -> next;
        
        return 0;
    }else if(tmp -> next && !tmp -> next -> next){
        tmp -> next = NULL;

        return 0;
    }

    return 1;
}