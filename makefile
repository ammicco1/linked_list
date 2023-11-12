main: main.o linked_list.o
	gcc -o main main.o linked_list.o -g

main.o: main.c 
	gcc -c main.c -o main.o -g

linked_list.o: linked_list.c 
	gcc -c linked_list.c -o linked_list.o -g

clean: 
	rm *.o main