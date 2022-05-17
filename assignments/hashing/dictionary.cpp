#include <iostream>
#include "dictionary.h"
#include "Person.h"

Dictionary::Dictionary() {
        for(int i = 0; i < 10; i++) {
                table[i] = new List();
        }
}

Dictionary::~Dictionary() {
        for(int i = 0; i < 10; i++) {
                delete table[i];
        }
}

int Dictionary::hash(Person *p) {
        return ((p->get_first().length() + p->get_last().length()) * 5) % 10;
}

void Dictionary::enter(Person *p) {
        table[this->hash(p)]->insert(p);
}

void Dictionary::enter(std::string first, std::string last, int id) {
        Person *p = new Person(first, last, id);
        this->enter(p);
}

Person* Dictionary::retrieve(Person *p) {
        Node *walker = table[this->hash(p)]->getHead();
        while(walker != nullptr) {
                if(walker->getPerson()->get_name() == p->get_name()) {
                        return walker->getPerson();
                }
        walker = walker->getNext();
        }
        return nullptr;
}

std::string Dictionary::getKeys() {
        std::string keys = "";
        for(int i = 0; i < 10; i++) {
                keys += table[i]->toString();
                keys += "\n";
        }
        return keys;
}
