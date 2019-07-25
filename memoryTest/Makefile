CC= g++
FLAGS= -std=c++14 -Wall -g
OBJS= 

all:memTest

memTest: memTest.cpp
	$(CC) $(FLAGS) memTest.cpp -o memTest $(OBJS)

clean:
	rm  *.o memTest memTest.tar

tar:
	tar cf memTest.tar memTest.scr Makefile memTest.cpp vector.h 