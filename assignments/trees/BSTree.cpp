#include <iostream>
#include "Node.h"
#include "BSTree.h"
/*
 * 
 BST - Binary Search Tree
 ordered tree where it's either empty or given a node N, all the
 values in N's left subtree are less than the value in N and all the
 values in N's right subtree are greater than the value in N.
*/
BSTree::BSTree(){
  root = nullptr;
}




// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n){
  std::string a;
  if (n==nullptr){
    return "";
  } else {

    /*
     *  pre-order traversal
     
     1. process the node
     2. recurse to left subtree
     3. recurse to right subtree
     a = std::to_string(n->getData());
     b =  traverse(n->getLeft());
     c =  traverse(n->getRight());
     * post-order traversal
     1. recurse to left subtree
     2. recurse to right subtree
     3. process the node
      
     a =  traverse(n->getLeft());
     b =  traverse(n->getRight());
     c = std::to_string(n->getData());
    */

    /*  
	in-order traversal
	1. recurse left subtree
	2. process node
	3. recurse right subtree
    */
    /*
    a =  traverse(n->getLeft());
    b = std::to_string(n->getData());
    c =  traverse(n->getRight());

    return a + ", " + b+ ", " + c;
    */
    a += std::to_string(n->getData());
    //traverse(n->getLeft());
    //traverse(n->getRight());
    return a + " " + traverse(n->getLeft()) + " " + traverse(n->getRight());
  }
};

std::string BSTree::get_debug_string(){
  return traverse(root);
};

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(7);
  n2->setRight(n);
  
}

int BSTree::search(int value){
  Node *t = root;

  while (t != nullptr){
    int tval = t->getData();
    if (tval==value){
      // here we'd really return a full object
      // with all the stuff associated with value
      // not just an int
      return value;
    }

    if (tval < value){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }
    
  }

  // if we get here then the value isn't
  // in the tree

  // normally, if we had a tree of objects
  // we could return null but since we only have
  // an int, we can't return an int to represent
  // not found so we'll throw an exception

  throw 1; // we should define our exceptions.

    
  
}

// we will always insert new nodes as leaves
void BSTree::insert(int value){

  // make a new node
  Node *newnode = new Node(value);
  
  // search for where the node would go as a leaf
  // that is, search until we get to null
  // we can use the piggyback strategy of having
  // a second pointer trail the lead pointer
  Node *p = root;
  Node *trailer;

  
  while (p != nullptr) {
    // note that trailer is one level behind
    trailer = p;
    if (p->getData() == value){
      // do the stuff when the node is already in the tree
      return;
    }
    else if (p->getData() < value){
      p = p->getRight(); 
    } else {
      p = p->getLeft();
    }
  }
  
  // handle the special case of the tree
  // being empty (null)
  if (root==nullptr){
    root=newnode;
  } else {
    // trailer points to the node ABOVE where the new node
    // will go.
    // we have to figure out if newnode goes on the
    // left of trailer or on the right of trailer
    if (trailer->getData() < value){
      trailer->setRight(newnode);
    } else {
      trailer->setLeft(newnode);
    }

  }
}
/*
int BSTree::rsearch(int value, Node *p) {
	if (p == nullptr) {
		throw 1;
	}
	int x = p->getData();
	if (x == value){
		return value;
	} else if (p->getData() < value) {
		rsearch(value, p->getLeft());
	} else {
		rsearch(value, p->getRight());
	}
}
*/
int BSTree::rsearch(int value) {
	return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *n){
  if (n==nullptr){
    throw 1;
  }

  int x = n->getData();
  if (x==value){
    return value;
  } else if (x>value){
    return rsearch(value,n->getLeft());
  } else {
    return rsearch(value,n->getRight());
  }
}

void BSTree::d(Node *p, int value) {
	Node *trailer = nullptr;
	if(p == nullptr) {
		throw 1;
	}
	while(p != nullptr) {
		if(p->getData() == value) {
			if(p->getRight() == nullptr || p->getLeft() == nullptr) { //Zero to one child
				if(p->getRight() == nullptr && p->getLeft() == nullptr) { //zero
					if(value > trailer->getData()) {
						delete p;
						p = nullptr;
						if(trailer != nullptr) {
							trailer->setRight(nullptr);
						}
						return;
					} else {
						delete p;
						p = nullptr;
						//trailer->setLeft(nullptr);
						if(trailer != nullptr) {
                                                        trailer->setLeft(nullptr);
                                                }
						return;
					}
				} else if(p->getLeft() != nullptr) { //one
					if(value > trailer->getData()) {
						if(trailer == nullptr) {
                                                        root = p->getLeft();
                                                } else {
							trailer->setRight(p->getLeft());
                                                	delete p;
                                                	p = nullptr;
                                                	return;
						}
                                        } else {
						if(trailer == nullptr) {
                                                        root = p->getRight();
                                                } else {
                                                        trailer->setLeft(p->getRight());
                                                delete p;
                                                p = nullptr;
                                                return;
						}
                                        }
				}
			} else {
				Node *lowest = p;
				while(lowest->getLeft() != nullptr){
					lowest = p->getLeft();
				}
				d(lowest->getData());
				p->setData(lowest->getData());
				return;
			}
		} else if (value > p->getData()) {
			trailer = p;
			p = p->getRight();
		} else {
			trailer = p;
			p = p->getLeft();
		}
	}
}

void BSTree::d(int value) {
	d(root, value);
}
