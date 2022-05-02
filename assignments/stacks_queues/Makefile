main: main.o stack.o Node.o
	g++ -o main main.o stack.o Node.o

main.o: main.cpp Node.h stack.h
	g++ -c -std=c++11 main.cpp

Node.o: Node.cpp Node.h

stack.o: stack.cpp stack.h Node.h
