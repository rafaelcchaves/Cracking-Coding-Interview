#include "tree.h"

Node* Tree::getRoot(){
	return root;
}

void Tree::visit(Node* node){
	if(node == NULL) return;
	std::cout << node->getValue() << std::endl;
}

void Tree::addNode(int value){
	Node *node = new Node(value);
	addNode(node);
}

bool Tree::removeNodeSubtree(int value){
    Node* parent = NULL;
    Node* current_node = root;

    while(current_node != NULL and current_node->getValue() != value){
	parent = current_node;
	if(value < current_node->getValue()){
	    current_node = current_node->getLeft();
	} else {
	    current_node = current_node->getRight();
	}
    }

    if(current_node == NULL)
	return false;
    
    if(current_node == root){
	root = NULL;
	return true;
    }
    
    if(parent->getLeft() == current_node)
	parent->removeLeft();
    
    if(parent->getRight() == current_node)
	parent->removeRight();

    return true;
}

void Tree::addNode(Node* node){
	if(root == NULL){
		root = node;
		return;
	}
	Node *current_node = root;
	while(true){
		if(current_node->getValue() > node->getValue()){
			if(current_node->addLeft(node))
				break;
			current_node = current_node->getLeft();
		}else{
			if(current_node->addRight(node))
				break;
			current_node = current_node->getRight();
		}
	}
}

void Tree::inOrder(Node* node){
	if(node == NULL) return;
	inOrder(node->getLeft());
	visit(node);
	inOrder(node->getRight());
}

void Tree::preOrder(Node* node){
	if(node == NULL) return;
	visit(node);
	preOrder(node->getLeft());
	preOrder(node->getRight());
}

void Tree::postOrder(Node* node){
	if(node == NULL) return;
	postOrder(node->getLeft());
	postOrder(node->getRight());
	visit(node);
}

