#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "doctest.h"
#include "OList.h"

TEST_CASE("INSERT") {
	OList *l1 = new OList();
        l1->insert(5);
        l1->insert(6);
        l1->insert(10);	
	l1->insert(18);
	CHECK(l1->toString() == "head --> 5 --> 6 --> 10 --> 18 --> nullptr");
	
	OList *l2 = new OList();
        l2->insert(-1);
        l2->insert(3);
        l2->insert(3);
        l2->insert(5);
	l2->insert(4);
        l2->insert(6);
	CHECK(l2->toString() == "head --> -1 --> 3 --> 3 --> 4 --> 5 --> 6 --> nullptr");	
}

TEST_CASE("Contains") {
	OList *l1 = new OList();
	CHECK(l1->contains(100) == false);

	l1->insert(-1);
	l1->insert(1);
	CHECK(l1->contains(-1) == true);
	CHECK(l1->contains(1) == true);
}

TEST_CASE("GET") {
	OList *l1 = new OList();
        l1->insert(5);
        l1->insert(6);
        l1->insert(10);
        l1->insert(18);
	CHECK(l1->get(0) == 5);
	CHECK(l1->get(1) == 6);
	CHECK(l1->get(2) == 10);
	CHECK(l1->get(3) == 18);
}

TEST_CASE("REMOVE") {
	OList *l2 = new OList();
        l2->insert(1);
        l2->insert(2);
        l2->insert(3);
        l2->insert(5);
        l2->insert(4);
        l2->insert(6);
	CHECK(l2->toString() == "head --> 1 --> 2 --> 3 --> 4 --> 5 --> 6 --> nullptr");
	l2->remove(1);
	CHECK(l2->toString() == "head --> 1 --> 3 --> 4 --> 5 --> 6 --> nullptr");
	l2->remove(1);
	l2->remove(1);
	l2->remove(1);
	CHECK(l2->toString() == "head --> 1 --> 6 --> nullptr");
}

TEST_CASE("REVERSE") {
	OList *l1 = new OList();
        l1->insert(5);
        l1->insert(6);
        l1->insert(10);
        l1->insert(18);
	l1->reverse();
	CHECK(l1->toString() == "head --> 18 --> 10 --> 6 --> 5 --> nullptr");

	OList *l2 = new OList();
        l2->insert(-5);
        l2->insert(-10);
        l2->insert(5);
        l2->insert(5);
	l2->reverse();
	CHECK(l2->toString() == "head --> 5 --> 5 --> -5 --> -10 --> nullptr");
}	
