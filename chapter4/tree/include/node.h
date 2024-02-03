#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <iostream>

class Node {
	private:
		int value;
		Node *left, *right;
	public:
		Node(int value): value(value) {};
		int getValue();
		Node* getLeft();
		Node* getRight();
		bool addLeft(Node *children);
		bool addRight(Node *children);
		bool removeLeft();
		bool removeRight();
};

#endif
