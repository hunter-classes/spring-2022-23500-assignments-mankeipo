#include "queues.h"
#include<vector>

Queues::Queues() {
	arr = new int[5];
	max_items = 5;	
	start = 0;
	end = 0;
	total_items = 0;	
}

Queues::~Queues() {
	delete[] arr;
}

bool Queues::is_empty() {
	if(start == end && total_items == 0) {
		return true;
	} else {
		return false;
	}
}

bool Queues::is_full() {
	if(total_items == max_items) {
		return true;
	} else {
		return false;
	}
}

void Queues::enqueue(int num) {
	if(is_full()){
		throw MAXQUEUES;
	} 
	arr[end] = num;
	end++;
	total_items++;
	if(end >= max_items) {
		end %= max_items;
	}
}

int Queues::dequeue() {
	if(is_empty()){
                throw EMPTYQUEUES;
        }
	int temp = arr[start];
	start++;
	total_items--;
	if(start >= max_items) {
                start %= max_items;
        }
	return temp;
}

int Queues::front() {
	if(is_empty()){
                throw EMPTYQUEUES;
        }
	return arr[start];
}
