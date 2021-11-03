CC =gcc
AR =ar
FLAG =-Wall -g
MAIN = mains maindloop maindrec
CALLS =loops recursives recursived loopd
FORLOOPS =basicClassification.o advancedClassificationLoop.o
FORRECU =basicClassification.o advancedClassificationRecursion.o

all: recursived recursives loopd loops mains maindloop maindrec

mains: main.o libclassrec.a
	$(CC) $(FLAG) -o mains main.o libclassrec.a -lm
maindloop: main.o
	$(CC) $(FLAG) -o maindloop main.o ./libclassloops.so -lm
maindrec: main.o
	$(CC) $(FLAG) -o maindrec main.o ./libclassrec.so -lm

recursives:libclassrec.a
loops:libclassloops.a
recursived:libclassrec.so
loopd:libclassloops.so

libclassloops.a:	basicClassification.o advancedClassificationLoop.o 
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
libclassrec.a:	basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o  
libclassrec.so:	basicClassification.o advancedClassificationRecursion.o
	$(CC) $(FLAG) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o
libclassloops.so:	basicClassification.o advancedClassificationLoop.o
	$(CC) $(FLAG) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAG) -c basicClassification.c 
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAG) -c advancedClassificationRecursion.c 
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAG) -c advancedClassificationLoop.c 
main.o: main.c NumClass.h
	$(CC) $(FLAG) -c main.c 

.PHONY: clean.
clean:
	rm -f *.o *.a *.so mains maindloop maindrec

