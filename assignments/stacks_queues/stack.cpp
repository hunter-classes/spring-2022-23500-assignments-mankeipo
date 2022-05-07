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

bool Stack::is_empty() {
	if(head == nullptr) {
		return true;
	} else {
		return false;
	}	
}
int Stack::pop() {
	if(is_empty()) {
		throw EMPTYSTACK;
	} else {
		//Node *trailer = nullptr;
		Node *walker = head;
		int temp = head->getData();
		head = walker->getNext();
		delete walker;
		return temp;
	}
}

int Stack::top() {
	if(is_empty()) {
                throw EMPTYSTACK;
        } else {
                return head->getData();
        }
}		
