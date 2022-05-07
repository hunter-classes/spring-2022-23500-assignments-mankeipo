#pragma once
#include "Node.h"
#define EMPTYSTACK 1

class Stack {
	private:
		Node *head;
	
	public:
		Stack();
		~Stack();
		void push(int);
		int pop();
		int top();
		bool is_empty();
};
