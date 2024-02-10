#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <iostream>

class Node {
	public:
		int value, balance, height;
		Node *left, *right;
		Node(int value): value(value), balance(0), height(1) {};
		void updateHeightAndBalance();
};

#endif
