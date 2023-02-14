#include "linked_list.h"
#include <stdio.h>
#include <stdbool.h>

linked_list *inzialize_linked_list(element *e){
    linked_list *tmp = (linked_list *) malloc(sizeof(linked_list));

    tmp -> elem = e;
    tmp -> next = NULL;

    return tmp;
}

void add_node(linked_list **list, element *e){
    linked_list *tmp = inzialize_linked_list(e);

    if(!(*list)){
        *list = tmp;
    }else{
        while((*list) -> next){
            *list = (*list) -> next;
        }

        (*list) -> next = tmp;
    }
}

bool list_include(linked_list *list, key *key){
    while(list){
        if(compare_key(list -> elem -> key, key) == 0){
            return true;
        }
        list = list -> next;
    }

    return false;
}

int delete_node(linked_list **list, key *k){
    linked_list *tmp = *list;

    if(!list_include(tmp, k)){
        printf("element %d not included!\n", get_key(k));
    }

    if(compare_key(tmp -> elem -> key, k) == 0){
        if(tmp -> next){
            *list = (*list) -> next;
            return 0;
        }else{
            *list = NULL;
            return 0;
        } 
    }

    while(tmp -> next){
        if(compare_key(tmp -> next -> elem -> key, k) == 0){
            if(tmp -> next){
                tmp -> next = tmp -> next -> next;
                return 0;
            }else{
                tmp -> next = NULL;
                return 0;
            } 
        }

        tmp = tmp -> next;
    }

    return -1;
}

int delete_node_from_index(linked_list **list, int index){
    int i;
    linked_list *tmp = *list;

    if(index > node_count(tmp)){
        printf("index's too high\n");
        return -1;
    }

    if(index == 0){
        *list = (*list) -> next;
        return 0;
    }

    for(i = 0; i < index - 1; i++){
        tmp = tmp -> next;
    }

    if(tmp -> next -> next == NULL){
        tmp -> next = NULL;
        return 0;
    }

    tmp -> next = tmp -> next -> next;

    return 0;
}

void print_all_list(linked_list *list){
    int i = 0;

    if(list == NULL){
        printf("the list is empty!\n");
    }else{
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
}

void swap_node(linked_list **list, int index1, int index2){
    int i = 0;
    linked_list *tmp = *list, *prev1 = NULL, *prev2 = NULL, *node1, *node2;

    if(index1 != index2){
        while(tmp){
            if(i == index1 - 1){
                prev1 = tmp;
            }
            if(i == index1){
                node1 = tmp;
            }
            if(i == index2 - 1){
                prev2 = tmp;
            }
            if(i == index2){
                node2 = tmp;
            }

            tmp = tmp -> next;
            i++;
        }

        if(prev1 != NULL){
            prev1 -> next = node2;
        }

        if(prev2 != NULL){
            prev2 -> next = node1;
        }

        tmp = node1 -> next;
        node1 -> next = node2 -> next;
        node2 -> next = tmp;

        if(prev1 == NULL){
            *list = node2;
        }
        
        if(prev2 == NULL){
            *list = node1;
        }
    }
}

int node_count(linked_list *list){
    int counter = 0;

    if(list == NULL){
        return 0;
    }else{
        while(list){
            counter++;
            list = list -> next;
        }
    }

    return counter;
}

linked_list *get_node_by_index(linked_list *list, int index){
    int i = 0;

    if(index > node_count(list)){
        printf("index too high for get node!\n");
        return NULL;
    }

    while(i < index){
        i++;
        list = list -> next;
    }

    return list;
}

int get_max_key(linked_list *list){
    int max = get_element_key(list -> elem);
    int max_tmp;

    while(list -> next){
        max_tmp = get_element_key((list -> next) -> elem);
        if(max < max_tmp){
            max = max_tmp;
        }

        list = list -> next;
    }

    return max;
}

int get_min_key(linked_list *list){
    int min = get_element_key(list -> elem);
    int min_tmp;

    while(list -> next){
        min_tmp = get_element_key((list -> next) -> elem);
        if(min > min_tmp){
            min = min_tmp;
        }

        list = list -> next;
    }

    return min;
}

int get_node_information(linked_list *list, int index){
    int i, next;
    linked_list *tmp = list, *prev_node; 

    if(index > node_count(list)){
        printf("INDEX TOO HIGH!\n");
        return -1;
    }else if(index < 0){
        printf("INDEX TOO LOW!\n");
        return -1;
    }

    if(index == 0){
        printf("NODE'S INDEX: %d\n\t- PREV: -1\n\t- NEXT: %d\n\t- NODE KEY: %d", index, get_element_key(list -> next -> elem), get_element_key(list -> elem));
    }else{
        for(i = 0; i != index; i++){
            if(i == index - 1){
                prev_node = tmp;
            }
            tmp = tmp -> next;
        }

        if(tmp -> next == NULL){
            next = -1;
        }else{
            next = get_element_key(tmp -> next -> elem);
        }

        printf("NODE'S INDEX: %d\n\t- PREV: %d\n\t- NEXT: %d\n\t- NODE KEY: %d", index, get_element_key(prev_node -> elem), next, get_element_key(tmp -> elem));
    }

    return 0;
}

int partition(linked_list **list, int first_ind, int last_ind){
    int x, y, i, j;

    x = get_element_key(get_node_by_index(*list, last_ind) -> elem);
    i = first_ind - 1;

    for(j = first_ind; j < last_ind; j++){
        y = get_element_key(get_node_by_index(*list, j) -> elem);
        
        if(y <= x){
            i++;
            swap_node(list, i, j);
        }
    }

    swap_node(list, i + 1, last_ind);

    return i + 1;
}

void quicksort(linked_list **list, int first_ind, int last_ind){
    int q;

    if(first_ind < last_ind){
        q = partition(list, first_ind, last_ind);
        quicksort(list, first_ind, q - 1);
        quicksort(list, q + 1, last_ind);
    }
}