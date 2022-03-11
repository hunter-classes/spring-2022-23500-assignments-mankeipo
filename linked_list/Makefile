main: main.o Node.o OList.o
	g++ -o main main.o Node.o OList.o

tests: tests.o Node.o OList.o
	g++ -o tests tests.o Node.o OList.o

main.o: main.cpp Node.h OList.h
	g++ -std=c++11 -c main.cpp

tests.o: tests.cpp Node.h OList.h
	g++ -std=c++11 -c tests.cpp

//List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

OList.o: OList.cpp OList.h Node.h

clean:
	rm -f main.o OList.o Node.o tests.o main tests
