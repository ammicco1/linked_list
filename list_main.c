#include "./include/linked_list.h"
#include <stdio.h>

int main(int argc, char **argv){
    int choise, key, index, exit = 1;
    linked_list *list;

	printf("Insert a key for the first node: ");
	scanf("%d", &key);
	list = initialize_linked_list(initialize_element(key));
	printf("ok.\n");

    while(exit){
        printf("\n---------------------------------------------\n");
        printf("What do you want to do?\n\
\t- 1:  Append a node\n\
\t- 2:  Insert a node at the beginning\n\
\t- 3:  Insert a node in a position\n\
\t- 4:  Delete the last node\n\
\t- 5:  Delete the first node\n\
\t- 6:  Delete a node in a position\n\
\t- 7:  Get the list's size\n\
\t- 8:  Get a node\n\
\t- 9:  Check if the list includes a key\n\
\t- 10: Reverse the list\n\
\t- 11: Print the list\n\
\t- 12: exit\n\
---------------------------------------------\n\
\nChoise: "); 
		scanf("%d", &choise);

		switch(choise){
			case 1: printf("Insert a key for the node to append: ");
					scanf("%d", &key);

					append_node(&list, initialize_element(key));
					printf("ok.\n");
					break;
			case 2: printf("Insert a key for the node to insert at the beginning: ");
					scanf("%d", &key);

					insert_head_node(&list, initialize_element(key));
					printf("ok.\n");
					break;
			case 3: printf("Insert a key for the node: ");
					scanf("%d", &key);
					printf("insert the index: ");
					scanf("%d", &index);

					insert_node(&list, initialize_element(key), index);
					printf("ok.\n");
					break;
			case 4: delete_last_node(&list);
					printf("ok.\n");
					break;
			case 5: delete_first_node(&list);
					printf("ok.\n");
					break;
			case 6: printf("Insert the index: ");
					scanf("%d", &index);
					
					delete_node(&list, index);
					break;
			case 7: printf("size: %d\n", size(list));
					break;
			case 8: printf("Insert the node index: ");
					scanf("%d", &index);

					printf("|k: %d|\n", get_node(list, index) -> element -> key);
					break;
			case 9: printf("Insert the key: ");
					scanf("%d", &key);

					if(list_include(list, key) == 1){
						printf("The list include the key\n");
					}else{
						printf("The list doesn't include the key\n");
					}
					break;
			case 10: list = reverse(&list, NULL);
					printf("ok.\n");
					break;
			case 11: print_list(list);
					break;
			case 12: exit = 0; printf("bye!\n"); break;
		}
	}

    return 0;
}