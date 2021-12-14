#include <stdio.h>
#include "linked_list.h"

int main(int argc, char **argv){

    int decision, key, exit = 0;
    linked_list *list;

    while(1){
        if(exit == 1){
            break;
        }
        printf("what do you want to do?\n\n 1: inzialize a linked list\n 2: insert a new node\n 3: delete a node by key\n 4: delete all node with a key key\n 5: delete an element by index\n 6: print all the list\n 7: exit\n\nchoose: ");
        scanf("%d", &decision);

        switch(decision){
            case 1: printf("\ninsert the first key: "); scanf("%d", &key);
                    list = inzialize_linked_list(inizialize_element(inzialize_key(key))); 
                    printf("done!\n"); break;
            case 2: printf("\ninsert the key of the new node: "); scanf("%d", &key);
                    add_node(list, inizialize_element(inzialize_key(key))); 
                    printf("done!\n"); break;
            case 3: printf("\ninsert the key of the node to delete: "); scanf("%d", &key);
                    list = delete_node(list, inzialize_key(key));
                    printf("done!\n"); break;
            case 4: printf("\ninsert the key of the node to delete: "); scanf("%d", &key);
                    while(list_include(list, inzialize_key(key))){
                        list = delete_node(list, inzialize_key(key));
                    } 
                    printf("done!\n"); break;
            case 5: printf("\ninsert the index of the node to delete: "); scanf("%d", &key);
                    list = delete_node_from_index(list, key);
                    printf("done!\n"); break;
            case 6: print_all_list(list); break;
            case 7: exit = 1; break;
        }
    }

    printf("\nbye\n");

    return 0;
}