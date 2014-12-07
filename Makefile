CC = g++
CCFLAGS = -Wall -g

#all: program1 program2 program3 program4 program5 program6 program7 program8
all: program8
	
#clean: clean1 clean2 clean3 clean4 clean5 clean6 clean7 clean8
clean: clean8

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


###PROGRAM 3#######################
program3: prog3/main.o DoubleStack.o Makefile
	${CC} ${CCFLAGS} -o program3 prog3/main.o DoubleStack.o

clean3:
	rm -f program3 prog3/main.o DoubleStack.o *.core

DoubleStack.o: DoubleStack.cpp DoubleStack.h Makefile
	${CC} ${CCFLAGS} -c DoubleStack.cpp
	
prog3/main.o: prog3/main.cpp DoubleStack.h Makefile
	${CC} ${CCFLAGS} -o prog3/main.o -c prog3/main.cpp

###PROGRAM 4#######################
program4: prog4/main.o Airport.o Makefile
	${CC} ${CCFLAGS} -o program4 prog4/main.o Airport.o

clean4:
	rm -f program4 prog4/main.o Airport.o *.core

Airport.o: Airport.cpp Airport.h Makefile
	${CC} ${CCFLAGS} -c Airport.cpp
	
prog4/main.o: prog4/main.cpp Airport.h Makefile
	${CC} ${CCFLAGS} -o prog4/main.o -c prog4/main.cpp

###PROGRAM 5#######################
program5: prog5/main.o mathTree.o Makefile
	${CC} ${CCFLAGS} -o program5 prog5/main.o mathTree.o

clean5:
	rm -f program5 prog5/main.o mathTree.o *.core

mathTree.o: mathTree.cpp mathTree.h Makefile
	${CC} ${CCFLAGS} -c mathTree.cpp
	
prog5/main.o: prog5/main.cpp mathTree.h Makefile
	${CC} ${CCFLAGS} -o prog5/main.o -c prog5/main.cpp
	
###PROGRAM 6#######################
program6: prog6/main.o BinarySearch.o Makefile
	${CC} ${CCFLAGS} -o program6 prog6/main.o BinarySearch.o

clean6:
	rm -f program6 prog6/main.o BinarySearch.o *.core

BinarySearch.o: BinarySearch.cpp BinarySearch.h Makefile
	${CC} ${CCFLAGS} -c BinarySearch.cpp
	
prog6/main.o: prog6/main.cpp BinarySearch.h Makefile
	${CC} ${CCFLAGS} -o prog6/main.o -c prog6/main.cpp

###PROGRAM 7#######################
program7: prog7/main.o HashTable.o Makefile
	${CC} ${CCFLAGS} -o program7 prog7/main.o HashTable.o

clean7:
	rm -f program7 prog7/main.o HashTable.o *.core

HashTable.o: HashTable.cpp HashTable.h Makefile
	${CC} ${CCFLAGS} -c HashTable.cpp
	
prog7/main.o: prog7/main.cpp HashTable.h Makefile
	${CC} ${CCFLAGS} -o prog7/main.o -c prog7/main.cpp

###PROGRAM 8#######################
program8: prog8/main.o sorting.o Makefile
	${CC} ${CCFLAGS} -o program8 prog8/main.o sorting.o

clean8:
	rm -f program8 prog8/main.o sorting.o *.core

sorting.o: sorting.cpp sorting.h Makefile
	${CC} ${CCFLAGS} -c sorting.cpp
	
prog8/main.o: prog8/main.cpp sorting.h Makefile
	${CC} ${CCFLAGS} -o prog8/main.o -c prog8/main.cpp
