#include "tree.h"

void Tree::visit(Node* node){
    if(node == NULL) return;
    std::cout << node->value << std::endl;
}

bool Tree::insert(int value){
    return insert(&root, value);
}

bool Tree::insert(Node** ptr, int value){
    Node* node = *ptr;
    if(node == NULL){
	*ptr = new Node(value); 
	return true;
    }

    if(value == node->value)
	return false;

    Node** ptr_left = &(node->left);
    Node** ptr_right = &(node->right);

    if(value < node->value)
	return insert(ptr_left, value);
    return insert(ptr_right, value);
}

bool Tree::remove(int value){
    return remove(&root, value);
}

bool Tree::remove(Node **ptr, int value){
    Node* node = *ptr;
    if(node == NULL)
	return false;
    
    if(value == node->value){
	*ptr = NULL;
	return true;
    }

    Node** ptr_left = &(node->left);
    Node** ptr_right = &(node->right);
    if(value < node->value)
	return remove(ptr_left, value);
    return remove(ptr_right, value);
}

int Tree::findMin(){
    if(root == NULL)
	return INT_MAX;
    Node* node = *findMin(&root);
    return node->value;
}
int Tree::findMax(){
    if(root == NULL)
	return INT_MIN;
    Node* node = *findMax(&root);
    return node->value;
}

Node** Tree::findMin(Node** ptr){
    Node* node = *ptr;
    if(node == NULL)
	return NULL;
    if(node->left == NULL)
	return ptr;
    return findMin(&(node->left));
}

Node** Tree::findMax(Node** ptr){
    Node* node = *ptr;
    if(node == NULL)
	return NULL;
    if(node->right == NULL)
	return ptr;
    return findMax(&(node->right));
}

void Tree::inOrder(Node* node){
	if(node == NULL) return;
	inOrder(node->left);
	visit(node);
	inOrder(node->right);
}

void Tree::preOrder(Node* node){
	if(node == NULL) return;
	visit(node);
	preOrder(node->left);
	preOrder(node->right);
}

void Tree::postOrder(Node* node){
	if(node == NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	visit(node);
}

