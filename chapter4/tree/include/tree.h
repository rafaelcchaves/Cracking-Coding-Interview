#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include "node.h"

class Tree {
    private:
	bool insert(Node** ptr, int value);
	bool remove(Node** ptr, int value);
	Node** findMin(Node** ptr);
	Node** findMax(Node** ptr);
    public:
	Tree(): root(NULL) {};
	bool remove(int value);
	bool insert(int value);
	int findMin();
	int findMax();
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
	void visit(Node* node);
	Node *root;
};

#endif
