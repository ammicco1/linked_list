#include "linked_list.h"

linked_list *initialize_linked_list(element *e){
    linked_list *tmp = (linked_list *) malloc(sizeof(linked_list));

    tmp -> element = e;
    tmp -> next = NULL;

    return tmp;
}

void insert_node(linked_list **list, element *element, int index){
    linked_list *node = initialize_linked_list(element);
    linked_list *tmp = (*list);
    int i;

    for(i = 0; i < index - 1; i++){
        tmp = tmp -> next;
    }

    node -> next = tmp -> next;
    tmp -> next = node;
}

void append_node(linked_list **list, element *e){
    linked_list *tmp = (*list);

    if(!tmp){
        tmp = initialize_linked_list(e);
    }else{
        while(tmp -> next){
            tmp = tmp -> next;
        }

        tmp -> next = initialize_linked_list(e);
    }
}

void insert_head_node(linked_list **list, element *e){
    linked_list *tmp = initialize_linked_list(e);

    tmp -> next = (*list);

    (*list) = tmp; 
}

int delete_node(linked_list **list, int index){
    int i;
    linked_list *tmp = *list;

    if(index > size(tmp)){
        return -1;
    }

    if(!tmp){
        return -2;
    }

    if(index == 0){
        (*list) = (*list) -> next;
        
        return 0;
    }

    for(i = 0; i < index - 1; i++){
        tmp = tmp -> next;
    }

    if(!tmp -> next){
        tmp = NULL;
    }else if(!(tmp -> next -> next)){
        tmp -> next = NULL;
    }else{
        tmp -> next = tmp -> next -> next;
    }

    return 0;
}

int delete_first_node(linked_list **list){
    linked_list *tmp = (*list);

    if((*list)){
        (*list) = (*list) -> next;

        free(tmp);

        return 0;
    }

    return -1;
}

int delete_last_node(linked_list **list){
    linked_list *tmp = (*list);

    if(!tmp){
        return -1;
    }

    if(!tmp -> next){
        tmp = NULL;

        return 0;
    }

    while(tmp -> next -> next){
        tmp = tmp -> next;
    }

    free(tmp -> next);
    tmp -> next = NULL;

    return 0;
}

int print_list(linked_list *list){
    int i = 0;

    if(!list){
        return -1;
    }

    while(list){
        printf("|i: %d|k: %d|", i, list -> element -> key);

        if(list -> next){
            printf(" -> ");
        }
        
        list = list -> next;
        i++;
    }

    return 0;
}

int list_include(linked_list *list, int key){
    while(list){
        if(list -> element -> key == key){
            return 1;
        }

        list = list -> next;
    }

    return -1;
}

int size(linked_list *list){
    int counter = 0;

    if(!list){
        return 0;
    }
    
    while(list){
        counter++;
        list = list -> next;
    }

    return counter;
}

linked_list *get_node(linked_list *list, int index){
    int i = 0;

    if(index > size(list) || index < 0){
        return NULL;
    }

    while(i < index){
        i++;
        list = list -> next;
    }

    return list;
}