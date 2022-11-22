FLAGS = -Wall -g
CC = gcc	#keep the abilty to change the compiler

all: recursived recursives loopd loops mains maindloop maindrec


mains: main.o libsclassrec.a
	$(CC) $(FLAGS) -o mains main.o ./libsclassrec.a -lm 

maindloop:main.o libsclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libsclassloops.so -lm

maindrec: main.o libsclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libsclassrec.so -lm


#a for static
loops:libsclassloops.a

recursives: libsclassrec.a
#so for dunamic
recursived: libsclassrec.so

loopd: libsclassloops.so

libsclassloops.so:basicClassification.o advancedClassiFicationLoop.o
	$(CC) $(FLAGS) -shared -o libsclassloops.so basicClassification.o advancedClassiFicationLoop.o

libsclassrec.so:basicClassification.o advancedClassificationRecursion.o
	$(CC) $(FLAGS) -shared -o libsclassrec.so basicClassification.o advancedClassificationRecursion.o


libsclassrec.a:basicClassification.o advancedClassificationRecursion.o
	ar -rcs libsclassrec.a basicClassification.o advancedClassificationRecursion.o

libsclassloops.a:basicClassification.o advancedClassiFicationLoop.o
	ar -rcs libsclassloops.a basicClassification.o advancedClassiFicationLoop.o

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c  basicClassiFication.c  


advancedClassiFicationLoop.o: advancedClassiFicationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassiFicationLoop.c 

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h 
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c 

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c NumClass.h


.PHONEY: clean
clean:
	rm -f *.o *.a *.so mains maindloop maindrec