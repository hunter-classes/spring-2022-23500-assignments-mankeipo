#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  BSTree *t = new BSTree();
  t->setup();
  //t->insert(10);
  //t->insert(2);
  std::cout <<  t->get_debug_string() << "\n";
  //int v = 15;
  //std::cout << t->rsearch(10) << std::endl;
  t->d(20);
  std::cout <<  t->get_debug_string() << "\n";
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
    
  return 0;
}
