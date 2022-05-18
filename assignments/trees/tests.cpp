#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Node.h"
#include "BSTree.h"

TEST_CASE("BSTree::rsearch") {
	BSTree *t = new BSTree();
	t->setup();
	CHECK(t->rsearch(10) == 10);
	CHECK(t->rsearch(5) == 5);
	CHECK(t->rsearch(3) == 3);
	CHECK(t->rsearch(7) == 7);
	CHECK(t->rsearch(20) == 20);
	CHECK(t->rsearch(15) == 15);
	CHECK(t->rsearch(30) == 30);
	t->insert(40);
	t->insert(50);
	CHECK(t->rsearch(40) == 40);
	CHECK(t->rsearch(50) == 50);
}	

TEST_CASE("BSTree::remove") {
	BSTree *t = new BSTree();
	t->setup();
	CHECK(t->get_debug_string() == "10 5 3   7   20 15   30  ");
	CHECK(t->rsearch(3) == 3);
	t->d(3);//no child
	try
  	{
    		t->rsearch(3);
  	}
  	catch (int e)
  	{
    		CHECK(e == 1);
  	}
	
	CHECK(t->rsearch(20) == 20);
	t->d(20);//one child
	try
        {
                t->rsearch(20);
        }
        catch (int e)
        {
                CHECK(e == 1);
        }
	
	CHECK(t->rsearch(5) == 5);
        t->d(5);//two child
        try
        {
                t->rsearch(5);
        }
        catch (int e)
        {
                CHECK(e == 1);
        }
}

TEST_CASE("count_leaves") {
	BSTree *t = new BSTree();
        t->setup();
	CHECK(t->countLeaves() == 4);
	t->d(3);
	t->d(7);
	t->d(15);
	t->d(30);
	CHECK(t->countLeaves() == 2);
	t->d(5);
	t->d(20);
	CHECK(t->countLeaves() == 1);		
}

TEST_CASE("height of a tree") {
	BSTree *t = new BSTree();
        t->setup();
	CHECK(t->height() == 3);
	t->insert(40);
	t->insert(50);
	t->insert(60);
	t->insert(70);
	CHECK(t->height() == 7);
}

TEST_CASE("sum at given level level") {
	BSTree *t = new BSTree();
        t->setup();
	CHECK(t->sumAtLevel(1) == 10);
	CHECK(t->sumAtLevel(2) == 25);
	CHECK(t->sumAtLevel(3) == 55);
}
