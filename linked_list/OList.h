#pragma once
#include "Node.h"

class OList {
	private:
		Node *head;
	public:
		OList();
		~OList();
		void insert(int data);
		std::string toString();
		bool contains(int value);
		int get(int loc);
		void remove(int loc);
		void reverse();
};
