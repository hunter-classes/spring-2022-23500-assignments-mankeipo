#pragma once
#define MAXQUEUES 1
#define EMPTYQUEUES 1
#include <vector>

class Queues{
        private:
		int *arr;
		int start, end, total_items, max_items;
        public:
                Queues();
		~Queues();
		void enqueue(int);
		int dequeue();
		int front();
		bool is_empty();
		bool is_full();
};
