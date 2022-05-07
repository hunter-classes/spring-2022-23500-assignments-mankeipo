#include <iostream>
#include "stack.h"
#include "queues.h"

int main(){
	/*
	Stack *stack = new Stack();
	stack->push(12);
	stack->push(11);
	std::cout << stack->top() << std::endl;
	std::cout << stack->pop() << std::endl;
	std::cout << stack->top() << std::endl;
	*/
	Queues *q = new Queues();
	q->enqueue(10);
	std::cout << q->front() << std::endl;
	std::cout << q->dequeue() << std::endl;
	q->enqueue(11);
	std::cout << q->front() << std::endl;
        std::cout << q->dequeue() << std::endl;
}
