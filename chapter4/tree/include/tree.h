#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <iostream>
#include "node.h"

class Tree {
	private:
		Node *root;
	public:
		Tree(): root(NULL) {};
		bool removeNodeSubtree(int value);
		void addNode(int value);
		void addNode(Node* node);
		void inOrder(Node* node);
		void preOrder(Node* node);
		void postOrder(Node* node);
		void visit(Node* node);
		Node* getRoot();
};

#endif
