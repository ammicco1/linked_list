#include <stdio.h>
#include "linked_list.h"

int main(int argc, char **argv){

    int decision, key, exit = 0;
    linked_list *list;

    while(1){
        if(exit == 1){
            break;
        }
        printf("what do you want to do?\n\n \
 1: inzialize a linked list\n \
 2: insert a new node\n \
 3: delete a node by key\n \
 4: delete an element by index\n \
 5: print all the list\n \
 6: exit\n\n \
choose: ");
        scanf("%d", &decision);

        switch(decision){
            case 1: printf("insert the first key: "); scanf("%d", &key);
                    list = inzialize_linked_list(inizialize_element(inzialize_key(key))); break;
            case 2: printf("insert the key of the new node: "); scanf("%d", &key);
                    add_node(list, inizialize_element(inzialize_key(key))); break;
            case 3: printf("insert the key of the node to delete: "); scanf("%d", &key);
                    list = delete_node(list, inzialize_key(key)); break;
            case 4: printf("insert the index of the node to delete: "); scanf("%d", &key);
                    list = delete_node_from_index(list, key); break;
            case 5: print_all_list(list); break;
            case 6: exit = 1; break;
        }
    }

    printf("bye");

    return 0;
}