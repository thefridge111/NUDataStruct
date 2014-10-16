CC = g++
CCFLAGS = -Wall -g

all: program1 program2 program3 program4

clean: clean1 clean2 clean3 program4


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
