#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "stack.h"
#include "queues.h"

TEST_CASE("Stack::push(int) and Stack::top()") {
	Stack *stack = new Stack();
        stack->push(12);
        CHECK(stack->top()==12);
	stack->push(11);
        CHECK(stack->top()==11);
	stack->push(10);
        CHECK(stack->top()==10);
}

TEST_CASE("Stack::pop()") {
	Stack *stack = new Stack();
	stack->push(12);
	stack->push(11);
	stack->push(10);
	CHECK(stack->pop()==10);
	CHECK(stack->pop()==11);
	CHECK(stack->pop()==12);
}

TEST_CASE("Stack::is_empty()") {
	Stack *stack = new Stack();
	CHECK(stack->is_empty()==true);
	stack->push(12);
	stack->push(11);
	stack->push(10);
	CHECK(stack->is_empty()==false);
	stack->pop();
	stack->pop();
	stack->pop();
	CHECK(stack->is_empty()==true);
}

TEST_CASE("Queues::enqueue(int) and Queues::front()"){
	Queues *q = new Queues();
        q->enqueue(10);
	CHECK(q->front()==10);
	q->dequeue();
	q->enqueue(11);
        CHECK(q->front()==11);
	q->dequeue();
	q->enqueue(12);
        CHECK(q->front()==12);
}

TEST_CASE("Queues::dequeue()"){
	Queues *q = new Queues();
	q->enqueue(10);
	q->enqueue(11);
	q->enqueue(12);
	CHECK(q->dequeue()==10);
	CHECK(q->dequeue()==11);
	CHECK(q->dequeue()==12);
}

TEST_CASE("Queues::is_empty() and Queues::is_full()"){
	Queues *q = new Queues();
	CHECK(q->is_empty() == true);
	q->enqueue(10);
	q->enqueue(10);
	q->enqueue(10);
	q->enqueue(10);
	q->enqueue(10);
	CHECK(q->is_full() == true);
}
