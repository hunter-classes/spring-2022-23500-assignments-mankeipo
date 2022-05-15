OBJECTS=main.o BSTree.o Node.o
TESTS = tests.o BSTree.o Node.o
LDFLAGS=
CXXFLAGS=

main: $(OBJECTS)
	g++ -o main $(OBJECTS)
BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h
	g++ -std=c++11 -c main.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp

tests: $(TESTS)
	g++ -o tests $(TESTS)

tests.o: tests.cpp Node.h BSTree.h
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f $(OBJECTS) main tests.o tests
