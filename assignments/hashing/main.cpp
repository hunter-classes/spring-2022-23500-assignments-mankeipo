#include <iostream>
#include "dictionary.h"
#include "Person.h"

int main() {
	Dictionary *dict = new Dictionary();
	
	Person *Lebron = new Person("Lebron", "James", 123);
	dict->enter(Lebron);
	dict->enter("James", "Harden", 456);
	dict->enter("Allen", "Iverson", 789);
	std::cout << dict->getKeys() << std::endl;
	Person *James = new Person("James", "Harden", 456);
	std::cout << dict->retrieve(James);
	std::cout << James << std::endl;
}
