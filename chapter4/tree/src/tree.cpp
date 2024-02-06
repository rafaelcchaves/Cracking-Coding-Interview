#include "tree.h"

void Tree::visit(Node* node){
    if(node == NULL) return;
    std::cout << node->value << std::endl;
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

Node** Tree::find(Node** ptr, int value){
    if(ptr == NULL)
	return NULL;
    Node* node = *ptr;
    if(node == NULL)
	return NULL;
    if(value == node->value)
	return ptr;
    return value < node->value?
		find(&(node->left), value) : find(&(node->right), value); 
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

int Tree::popMin(Node** ptr){
    Node** ptr_to_min = findMin(ptr);
    if(ptr_to_min == NULL)
	return INT_MAX;
    Node* min_node = *ptr_to_min;
    if(min_node == NULL)
	return INT_MAX;
    *ptr_to_min = min_node->right; // link the right child of min to its parent
    int min_value = min_node->value;
    delete min_node;
    return min_value;
}

int Tree::popMax(Node** ptr){
    Node** ptr_to_max = findMax(ptr);
    if(ptr_to_max == NULL)
	return INT_MIN;
    Node* max_node = *ptr_to_max;
    if(max_node == NULL)
	return INT_MIN;
    *ptr_to_max = max_node->left; // link the left child of max to its parent
    int max_value = max_node->value;
    delete max_node;
    return max_value;
}

bool Tree::remove(int value){
    Node** ptr_to_node = find(&root, value);
    if(ptr_to_node == NULL)
	return false;
    
    Node* node = *ptr_to_node;
    if(node == NULL)
	return false;
    
    if(node->left == NULL and node->right == NULL){
	*ptr_to_node = NULL;
	delete node;
	return true;
    }
    
    if(node->left == NULL){
	node->value = popMin(ptr_to_node);
	return true;
    }

    node->value = popMax(ptr_to_node); 
    return true;
}

bool Tree::insert(int value){
    return insert(&root, value);
}

bool Tree::find(int value){
    return find(&root, value) != NULL;
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

int Tree::popMin(){
    return popMin(&root);
}

int Tree::popMax(){
    return popMax(&root);
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

