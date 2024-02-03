#include "node.h"

int Node::getValue(){
	return value;
}

bool Node::addLeft(Node *children){
	if(left != NULL) return false;
	left = children; return true;
}

bool Node::removeLeft(){
	if(left == NULL) return false;
	left = NULL; return true;
}

Node* Node::getLeft(){
	return left;
}

bool Node::addRight(Node *children){
	if(right != NULL) return false;
	right = children; return true;
}

bool Node::removeRight(){
	if(right == NULL) return false;
	right = NULL; return true;
}

Node* Node::getRight(){
	return right;
}





