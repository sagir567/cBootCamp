FLAGS = -Wall -g
CC = gcc

mains:main.o libclass.so
	$(CC) $(FLAGS) -o mains main.o libclass.so

main.o:main.c directedGraph.h 
	$(CC) $(FLAGS) -c main.c 

libclass.so:directedGraph.o
	$(CC) $(FLAGS) -shared -o ./libclass.so directedGraph.o

directedGraph.o:directedGraph.c directedGraph.h
	$(CC) $(FLAGS) -c directedGraph.c


.PHONY: clean 

clean: 
	rm -f *.o *.a *.so mains graphAlgos