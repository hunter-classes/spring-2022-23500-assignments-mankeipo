#pragma once
#include <iostream>
#include <stdio.h>


class BSTree{
 private:
  Node *root;
  std::string traverse(Node *n);

public:
  BSTree();

  void setup();

  std::string get_debug_string();
  

  // std::string traverse(Node *n);
   void d(Node *p, int value);
   void d(int value);
  //void remove(int value);
   int search(int value);
   void insert(int value);
   int rsearch(int value);
   int rsearch(int value, Node *p);
  // int treesum();
  // int treesum(Node *n);
  // int searchr(int value);
  // int searchr(int value, Node *n);
   int countLeaves();
   int countLeaves(Node *p);
   int height();
   int height(Node *p); 
   int sumAtLevel(Node *p, int level,int currentLevel);
   int sumAtLevel(int level);
   //void rinsert(int value);
   //void rinsert(Node *p, int value);
};
