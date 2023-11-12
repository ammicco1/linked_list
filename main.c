#include "linked_list.h"
#include <stdio.h>

int main(int argc, char **argv){
    struct linked_list *my_list, *tmp;
    int choice = 0;
    int key; 
    char *buff = (char *) malloc(sizeof(char) * 256);

    printf("LINKED LIST TESTING\n--------------------------\nInitilize the List. First key: ");
    scanf(" %d", &key);  
    printf("First value (str): ");
    scanf(" %s", buff);

    my_list = linked_list_initialize(key, buff, sizeof(char) * strlen(buff) + 1);

    while(1){
        printf("\nSelect an action:\n - 1: Insert a node\n - 2: Delete a node\n - 3: Search a node\n\n");
        scanf(" %d", &choice);

        switch(choice){
            case 1: 
                printf("Key: "); 
                scanf(" %d", &key); 
                
                printf("Value (str): "); 
                scanf(" %s", buff); 

                if(linked_list_search(my_list, key)){
                    fprintf(stderr, "\nInsert error - already used key\n");
                    break;
                }
                
                if(linked_list_insert(my_list, key, buff, sizeof(char) * strlen(buff) + 1) == 0){
                    printf("\nInsert ok\n");
                }else{
                    fprintf(stderr, "\nInsert error\n");
                }
                
                break;
            case 2: 
                printf("Key: ");
                scanf(" %d", &key);

                if(!linked_list_search(my_list, key)){
                    fprintf(stderr, "\nDelete error - no node with this key\n");
                    break;
                }

                if(linked_list_delete(my_list, key) == 0){
                    printf("\nDelete ok\n");
                }else{
                    fprintf(stderr, "\nDelete error\n");
                }

                break;
            case 3:
                printf("Key: ");
                scanf(" %d", &key);

                tmp = linked_list_search(my_list, key);

                if(tmp){
                    printf("\n%d -> %s\n", tmp -> key, (char *) tmp -> value);
                }else{
                    fprintf(stderr, "\nSearch error\n");
                }

                break;
        }
    }


    return 0;
}