#pragma once 
#include <iostream>
#include "List.h"
#include "Person.h"

class Dictionary {
	private: 
		List *table[10];
	
	public:
		Dictionary();
		~Dictionary();
		int hash(Person *p);
		void enter(Person *p);
		void enter(std::string first, std::string last, int id);
		Person* retrieve(Person *p);
		std::string getKeys();
};
