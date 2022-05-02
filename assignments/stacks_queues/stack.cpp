#include "stack.h"

Stack::Stack() {
	head = nullptr;
}

Stack::~Stack(){
  Node *trailer;
  std::cerr << "Destructing\n";
  while(head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}

void Stack::push(int data){
        //create a new Node
        Node *new_node = new Node(data);
        //insert the new Node
        new_node->setNext(head);
        head=new_node;
}


int Stack::pop() {
	if(is_empty()) {
		throw;
	} else {
		Node *trailer = nullptr;
		Node *walker = head;
		int temp = head->getData();
		trailer = walker;
		walker = walker->getNext();
		delete trailer;
		return temp;
	}
}		
