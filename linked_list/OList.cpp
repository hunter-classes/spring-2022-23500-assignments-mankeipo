#include <iostream>
#include "OList.h"

OList::OList() {
	head = nullptr;
}

OList::~OList() {
	Node *trailer;
	std::cerr << "Destructing/n";
	while(head != nullptr) {
    	trailer = head;
    	head = head->getNext();
    	delete trailer;
  	}
}

void OList::insert(int data){
	Node *tmp = new Node(data);
	Node *walker = head;
	Node *trailer = nullptr;
	
  	if(head == nullptr) {
  		tmp->setNext(head);
  		this->head = tmp;
		return;
	}
	while(walker != nullptr && (data > walker->getData())) {
		trailer = walker;
		walker = walker->getNext();
	}
	if(trailer == nullptr) {
		tmp->setNext(head);
                this->head = tmp;
        } else {
		trailer->setNext(tmp);
		tmp->setNext(walker);
	}
}

std::string OList::toString(){
  std::string result = "head --> ";
  Node *walker = this->head;
  while (walker != nullptr){
    result = result + std::to_string(walker->getData()) + " --> ";
    walker = walker->getNext();
  }
  result = result + "nullptr";
  return result;
}

bool OList::contains(int value) {
	Node *walker = head;
	while(walker != nullptr) {
		if(walker->getData() == value) {
			return true;
		}
		walker = walker->getNext();
	}
	return false;
		
}

int OList::get(int loc) {
	Node *walker = head;
	while(walker && loc > 0) {
		walker = walker->getNext();
		loc--;
	}
	if(walker) {
		return walker->getData();
	} else {
		return -1;
	}

}

void OList::remove(int loc) {
	Node *walker = head;
	Node *trailer=nullptr;
	while (walker != nullptr && loc > 0){
		trailer = walker;
		walker = walker->getNext();
		loc = loc - 1;
	}
	if (walker == nullptr){
		throw std::out_of_range("Out of range");
	}
	if (trailer==nullptr){
		head = walker->getNext();
		delete walker;
	} else {
		trailer->setNext(walker->getNext());
		delete walker;
	}
}

void OList::reverse() {
	Node *walker = head;	
	Node *trailor = nullptr;
	Node *previous = head;
	
	while(walker != nullptr) {
		walker = walker->getNext();
		previous->setNext(trailor);
		trailor = previous;
	        previous = walker;	
	}
	//std::cout << walker->getData() << std::endl;
	std::cout << trailor->getData() << std::endl;
	std::cout << (trailor->getNext())->getData() << std::endl;
	//std::cout << previous->getData() << std::endl;
	head = trailor;
}
