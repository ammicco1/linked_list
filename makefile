FLAGS = -Wall -ansi -pedantic
OBJS = list_main.o key.o element.o linked_list.o
EXEC = list_main

$(EXEC): $(OBJS)
	gcc $(FLAGS) -o $(EXEC) $(OBJS)

$(EXEC).o: $(EXEC).c
	gcc $(FLAGS) -c $(EXEC).c

linked_list.o: linked_list.c
	gcc $(FLAGS) -c linked_list.c

element.o: element.c
	gcc $(FLAGS) -c element.c

key.o: key.c
	gcc $(FLAGS) -c key.c

clean: 
	rm -f *.o $(EXEC) $(OBJS)