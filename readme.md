# Linked List

Simple C implementation of a linked list. 
The list is defined as a struct of the type: 
```c
struct linked_list{
    struct linked_list *next;

    int key; 
    void *value;
};
```

Where: 
 - next is a pointer to the next node
 - key is an integer value
 - value can be everything. In main.c it can be a string

There are 4 basic operation: 
 - initialize, that create the list
 - insert, to insert a new node
 - delete, to delete a node by key
 - search, to search a node by key 

In this example you can not insert different nodes with the same key. 

Try it with: 
```bash
$ make 
$ ./main
```

Or include it in your projects. 

Enjoy :) 