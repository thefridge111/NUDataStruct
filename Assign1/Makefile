CC = g++
CCFLAGS = -Wall -g

all: program1 program2

clean: clean1 clean2


###PROGRAM 1#######################
program1: prog1/main.o array.o Makefile
	${CC} ${CCFLAGS} -o program1 prog1/main.o array.o

clean1:
	rm -f program1 prog1/main.o array.o *.core

array.o: array.cpp array.h Makefile
	${CC} ${CCFLAGS} -c array.cpp
	
prog1/main.o: prog1/main.cpp array.h Makefile
	${CC} ${CCFLAGS} -o prog1/main.o -c prog1/main.cpp
	
###PROGRAM 2#######################
program2: prog2/main.o LinkedList.o Makefile
	${CC} ${CCFLAGS} -o program2 prog2/main.o LinkedList.o

clean2:
	rm -f program2 prog2/main.o LinkedList.o *.core

LinkedList.o: LinkedList.cpp LinkedList.h Makefile
	${CC} ${CCFLAGS} -c LinkedList.cpp
	
prog2/main.o: prog2/main.cpp LinkedList.h Makefile
	${CC} ${CCFLAGS} -o prog2/main.o -c prog2/main.cpp
