#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <iostream>

class Node {
	public:
		int value;
		Node *left, *right;
		Node(int value): value(value) {};
		bool addLeft(Node *children);
		bool addRight(Node *children);
		bool removeLeft();
		bool removeRight();
};

#endif
