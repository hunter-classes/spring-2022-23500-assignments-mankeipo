#include <iostream>
#include "stack.h"

int main(){
	Stack *stack = new Stack();
	stack->push(12);
	std::cout << stack->pop() << std::endl;
}
