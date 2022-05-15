#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  BSTree *t = new BSTree();
  t->setup();
  //t->insert(40);
  //t->insert(50);
  std::cout <<  t->get_debug_string() << "\n";
  t->d(3);
  t->d(5);
  t->d(20);
  std::cout <<  t->get_debug_string() << "\n";
  //int v = 15;
  //std::cout << t->rsearch(10) << std::endl;
  //t->d(20);
  //std::cout <<  t->get_debug_string() << "\n";
  //std::cout << t->rsearch(3) << std::endl;
  // try {
  //   int x  = t->searchr(v);
  //     std::cout << x << "\n";
  //   } catch (int e){
  //     std::cout << v << " not found\n";
    
  //   }

  //   t->insert(22);
  //   std::cout <<  t->get_debug_string() << "\n";
  //   t->insert(3);
  //   std::cout <<  t->get_debug_string() << "\n";

  //   std::cout << t->treesum() << "\n";
  std::cout << t->countLeaves() << std::endl;
  //std::cout << t->height() << std::endl;
  //std::cout << t->sumAtLevel(3) << std::endl;
  return 0;
}
