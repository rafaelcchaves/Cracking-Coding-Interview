#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include "node.h"

class Tree {
    private:
	int nodes;
	bool insert(Node** ptr, int value);
	bool remove(Node** ptr, int value);
	Node** find(Node** ptr, int value);
	Node** findMin(Node** ptr);
	Node** findMax(Node** ptr);
	int popMin(Node** ptr);
	int popMax(Node** ptr);
	void rightRotation(Node** ptr);
	void leftRotation(Node** ptr);
    public:
	Tree(): root(NULL), nodes(0) {};
	bool remove(int value);
	bool insert(int value);
	bool find(int value);
	int findMin();
	int findMax();
	int popMin();
	int popMax();
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
	void visit(Node* node);
	int size();
	Node* root;
};

#endif
