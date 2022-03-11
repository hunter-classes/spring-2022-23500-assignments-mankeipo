#include <iostream>
#include "List.h"
#include "Node.h"
#include "OList.h"
void Nodes();
void LinkedList();
void OLists();
int main(){
  	//LinkedList();
	OLists();

  	return 0;
}
/*
void LinkedList(){
  	List *l1 = new List();

	std::cout << l1->toString() << "\n";
  	l1->insert("a");
	l1->insert("b");
  	l1->insert("c");
  	std::cout << l1->toString() << "\n";
}

void Nodes(){
  	Node *p1 = new Node(); //creates a p1 memory block that points to a blank Node
  	p1->setData("hello"); // (*p1.setData()) -- refers to what p1 is pointing to, a blank Node. set its data

  	Node *p2 = new Node("World"); //creates a p2 memory block that points to a blank Node, with its data set as "World"

  	p1->setNext(p2); //points the p1 head Node to the p2 Node

  	std::cout << p1->getData() << "\n";
  	std::cout << p2->getData() << "\n";
  	//(p1 pointer) --> head Node --> (p2 pointer) --> Node's Data
  	std::cout << p1->getNext()->getData() << "\n";

  	p2 = new Node("!");
  	p1->getNext()->setNext(p2);

  	Node *walker = p1;
  	std::cout << "\n" << walker->getData() << "\n";
  	walker = walker->getNext();
  	std::cout << walker->getData() << "\n";
  	walker = walker->getNext();
  	std::cout << walker->getData() << "\n";
}
*/
void OLists() {
	OList *l1 = new OList();
	l1->insert(2);
	l1->insert(1);
	l1->insert(3);
	std::cout << l1->toString() << std::endl;
	std::cout << l1->contains(2) << std::endl;
	std::cout << l1->get(2) << std::endl;
	l1->remove(1);
	std::cout << l1->toString() << std::endl;
	l1->insert(2);
	l1->insert(5);
	l1->insert(4);
	l1->insert(6);
	std::cout << l1->toString() << std::endl;
	l1->reverse();
	std::cout << l1->toString() << std::endl;	
}
