HERE'S AN IMPLEMENTATION OF A LINKED LIST. 
THE LIST CONTAINS: 
 - AN ELEMENT THAT CONTAINS A KEY (IN THIS CASE AN INT), AND CAN CONTAINS OTHER INFORMATION.
 - A POINTER TO THE NEXT NODE 

THE LIST'S HAS THE ESSENTIAL FUNCTIONS LIKE:
 - INZIALIZE LIST
 - ADD A NEW NODE
 - DELETE NODE
 - INCLUDE AN ELEMENT
 - SWAP TWO NODES
 - COUNT THE NODES
 - PRINT ALL THE LIST
 - GET NODE BY INDEX
 - GET MAX AND MIN KEY IN THE LIST
 - QUICKSORT ALGORITHM

WITH THE LIST_MAIN TEST PROGRAM YOU CAN TEST ALL THE FUNCTIONS AND AFTER THAT YOU CAN MODIFY THE CODE OF KEY, ELEMENT AND LINKED_LIST TO CREATE THE LIST THAT YOU WILL SERVE

IF YOU USE LINUX USE THE MAKEFILE, IF YOU USE WINDOWS:
 - PASTE THEESE COMMANDS IN CMD TO COMPILE:
    - gcc -Wall -ansi -pedantic -c key.c element.c linked_list.c list_main.c
    - gcc -Wall -ansi -pedantic -o list_main.exe key.o element.o linked_list.o list_main.o

- AND THIS TO CLEAN:
    - del *.o 
    - del *.exe