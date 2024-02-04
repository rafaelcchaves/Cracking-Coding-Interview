#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <iostream>
#include "node.h"

class Tree {
	private:
		bool insert(Node** ptr, int value);
		bool remove(Node** ptr, int value);
	public:
		Tree(): root(NULL) {};
		bool remove(int value);
		bool insert(int value);
		void inOrder(Node* node);
		void preOrder(Node* node);
		void postOrder(Node* node);
		void visit(Node* node);
		Node *root;
};

#endif
