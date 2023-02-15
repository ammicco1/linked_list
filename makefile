FLAGS = -Wall -ansi -pedantic
OBJS = list_main.o element.o linked_list.o
EXEC = list_main

$(EXEC): $(OBJS)
	gcc $(FLAGS) -o $(EXEC) $(OBJS)

$(EXEC).o: $(EXEC).c
	gcc $(FLAGS) -c $(EXEC).c

linked_list.o: ./src/linked_list.c
	gcc $(FLAGS) -c ./src/linked_list.c

element.o: ./src/element.c
	gcc $(FLAGS) -c ./src/element.c

clean: 
	rm -f *.o $(EXEC) $(OBJS)
