#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dictionary.h"

TEST_CASE("hash") {	
	Dictionary *dict = new Dictionary();
	Person *Lebron = new Person("Lebron", "James", 1984);
	Person *James = new Person("James", "Harden", 1989);
	Person *Allen = new Person("Allen", "Iverson", 1975);
	CHECK(dict->hash(Lebron) == (11 * 5) % 10);
	CHECK(dict->hash(James) == (11 * 5) % 10);
	CHECK(dict->hash(Allen) == (12 * 5) % 10);
}

TEST_CASE("retrieve + enter") {
	Dictionary *dict = new Dictionary();
	Person *Lebron = new Person("Lebron", "James", 1984);
        Person *James = new Person("James", "Harden", 1989);
        Person *Allen = new Person("Allen", "Iverson", 1975);
	Person *Michael = new Person("Michael", "Jordan", 1963);
	dict->enter(Lebron);
	dict->enter(James);
	dict->enter(Allen);
	CHECK(dict->retrieve(Lebron)->get_name() == Lebron->get_name());
	CHECK(dict->retrieve(James)->get_name() == James->get_name());
	CHECK(dict->retrieve(Allen)->get_name() == Allen->get_name());
	CHECK(dict->retrieve(Michael) == nullptr);
}

TEST_CASE("get_keys") {
	Dictionary *dict = new Dictionary();
	Person *Lebron = new Person("Lebron", "James", 1984);
        Person *James = new Person("James", "Harden", 1989);
        Person *Allen = new Person("Allen", "Iverson", 1975);
        dict->enter(Lebron);
        dict->enter(James);
        dict->enter(Allen);
	CHECK(dict->getKeys() == "Iverson, Allen-->nullptr\nnullptr\nnullptr\nnullptr\nnullptr\nHarden, James-->James, Lebron-->nullptr\nnullptr\nnullptr\nnullptr\nnullptr\n");
}
