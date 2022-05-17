main: main.o stack.o Node.o queues.o
	g++ -o main main.o stack.o Node.o queues.o

main.o: main.cpp Node.h stack.h queues.h
	g++ -c -std=c++11 main.cpp

Node.o: Node.cpp Node.h

stack.o: stack.cpp stack.h Node.h

queues.o: queues.cpp queues.h
	g++ -c -std=c++11 queues.cpp

tests: tests.o stack.o Node.o queues.o
	g++ -o tests tests.o stack.o Node.o queues.o

tests.o: tests.cpp Node.h stack.h queues.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f tests.o main.o List.o Node.o stack.o queues.o main tests
