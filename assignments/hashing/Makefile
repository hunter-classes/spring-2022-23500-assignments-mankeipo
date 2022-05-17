main: main.o Node.o Person.o dictionary.o List.o
	g++ -o main main.o Node.o Person.o dictionary.o List.o

dictionary.o: dictionary.cpp dictionary.h Person.h List.h Node.h
	g++ -std=c++11 -c dictionary.cpp

List.o: List.cpp List.h Node.h Person.h
	g++ -std=c++11 -c List.cpp

main.o: main.cpp dictionary.h Person.h List.h Node.h
	g++ -std=c++11 -c main.cpp

Node.o: Node.cpp Node.h Person.h
	g++ -std=c++11 -c Node.cpp

Person.o: Person.cpp Person.h
	g++ -std=c++11 -c Person.cpp

tests: tests.o Node.o List.o dictionary.o Person.o
	g++ -o tests tests.o Node.o List.o dictionary.o Person.o

tests.o: tests.cpp dictionary.h
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f Node.o Person.o dictionary.o List.o main tests main.o tests.o
