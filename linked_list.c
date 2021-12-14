#include "linked_list.h"
#include <stdio.h>
#include <stdbool.h>

linked_list *inzialize_linked_list(element *elem){
    linked_list *tmp = (linked_list *) malloc(sizeof(linked_list));

    tmp -> elem = elem;
    tmp -> next = NULL;

    return tmp;
}

void add_node(linked_list *list, element *elem){
    linked_list *tmp = inzialize_linked_list(elem);
    
    while(list -> next){
        list = list -> next;
    }

    list -> next = tmp;
}

bool list_include(linked_list *list, key *key){
    while(list -> next){
        if(compare_key(list -> elem -> chiave, key) == 0){
            return true;
        }
        list = list -> next;
    }

    if(compare_key(list -> elem -> chiave, key) == 0){
            return true;
    }else{
        return false;
    }
}

linked_list *delete_node(linked_list *list, key *chiave){
    linked_list *tmp = list;

    if(!list_include(list, chiave)){
        printf("element %d not included!\n", get_key(chiave));
        return list;
    }

    if(compare_key(list -> elem -> chiave, chiave) == 0){
        if(list -> next){
            return tmp -> next;
        }else{
            return NULL;
        } 
    }

    while(list -> next){
        if(compare_key(list -> next -> elem -> chiave, chiave) == 0){
            if(list -> next){
                list -> next = list -> next -> next;
                return tmp;
            }else{
                list -> next = NULL;
                return tmp;
            } 
        }

        list = list -> next;
    }
}

linked_list *delete_node_from_index(linked_list *list, int index){
    int i;
    linked_list *tmp = list;

    if(index == 0){
        return list -> next;
    }

    for(i = 0; i < index - 1; i++){
        if(list -> next == NULL){
            printf("index's too much big\n");
            return tmp;
        }
        list = list -> next;
    }

    if(list -> next -> next == NULL){
        list -> next = NULL;
        return tmp;
    }

    list -> next = list -> next -> next;

    return tmp;
}

void print_all_list(linked_list *list){
    int i = 0;
	while(list -> next){
        if(get_element_key(list -> elem) < 10){
            printf("---------\n|   %d   |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
        }else if(get_element_key(list -> elem) >= 100){
            printf("---------\n|  %d  |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
        }else{
            printf("---------\n|   %d  |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
        }
		list = list -> next;
		i++;
	}
	if(get_element_key(list -> elem) < 10){
        printf("---------\n|   %d   |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
    }else if(get_element_key(list -> elem) >= 100){
        printf("---------\n|  %d  |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
    }else{
        printf("---------\n|   %d  |\n---------\n    |    \n    v    \n", get_element_key(list -> elem));
    }
}