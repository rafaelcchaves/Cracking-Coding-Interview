#include "tree.h"

void Tree::visit(Node* node){
    if(node == NULL) return;
    std::cout << node->value << ' ' << node->height << ' ' << node->balance <<  std::endl;
}

bool Tree::insert(Node** ptr, int value){
    Node* node = *ptr;
    if(node == NULL){
	*ptr = new Node(value); 
	return true;
    }

    if(value == node->value)
	return false;

    bool success = value < node->value? 
		    insert(&node->left, value) : insert(&node->right, value);

    node->updateHeightAndBalance();
    
    if(node->balance < -1){
	if(value > (node->left)->value)
	    leftRotation(&node->left);
	rightRotation(ptr);
    }

    if(node->balance > 1){
	if(value < (node->right)->value)
	    rightRotation(&node->right);
	leftRotation(ptr);
    }

    return success;
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
		find(&node->left, value) : find(&node->right, value); 
}

Node** Tree::findMin(Node** ptr){
    Node* node = *ptr;
    if(node == NULL)
	return NULL;
    if(node->left == NULL)
	return ptr;
    return findMin(&node->left);
}

Node** Tree::findMax(Node** ptr){
    Node* node = *ptr;
    if(node == NULL)
	return NULL;
    if(node->right == NULL)
	return ptr;
    return findMax(&node->right);
}

int Tree::popMin(Node** ptr){
    if(ptr == NULL)
	return INT_MAX;
    Node* node = *ptr;
    if(ptr == NULL)
	return INT_MAX;

    int value;
    if(node->left == NULL){
	value = node->value;
	*ptr = node->right;
	delete node;
	return value;
    }
    value = popMin(&node->left);
    node->updateHeightAndBalance();
    
    node->updateHeightAndBalance();
    if(node->balance < -1){
	if(node->left->balance >= 1)
	    leftRotation(&node->left);
	rightRotation(ptr);
    }

    if(node->balance > 1){
	if(node->right->balance <= -1)
	    rightRotation(&node->right);
	leftRotation(ptr);
    }

    return value;
}

int Tree::popMax(Node** ptr){
    if(ptr == NULL)
	return INT_MIN;
    Node* node = *ptr;
    if(node == NULL)
	return INT_MIN;

    int value;    
    if(node->right == NULL){
	value = node->value;
	*ptr = node->left;
	delete node;
	return value;
    }     

    value = popMax(&node->right);
    node->updateHeightAndBalance();

    node->updateHeightAndBalance();
    if(node->balance < -1){
	if(node->left->balance >= 1)
	    leftRotation(&node->left);
	rightRotation(ptr);
    }

    if(node->balance > 1){
	if(node->right->balance <= -1)
	    rightRotation(&node->right);
	leftRotation(ptr);
    }

    return value; 
}

void Tree::rightRotation(Node** ptr){
    if(ptr == NULL)
	return;
    Node* old_parent = *ptr;
    if(old_parent == NULL or old_parent->left == NULL)
	return;
    Node* new_parent = old_parent->left;
    *ptr = new_parent; 
    old_parent->left = new_parent->right;
    new_parent->right = old_parent;
    old_parent->updateHeightAndBalance();
    new_parent->updateHeightAndBalance();
}

void Tree::leftRotation(Node** ptr){
    if(ptr == NULL)
	return;
    Node* old_parent = *ptr;
    if(old_parent == NULL or old_parent->right == NULL)
	return;
    Node* new_parent = old_parent->right;
    *ptr = new_parent;
    old_parent->right = new_parent->left;
    new_parent->left = old_parent;
    old_parent->updateHeightAndBalance();
    new_parent->updateHeightAndBalance();
}

bool Tree::remove(Node** ptr, int value){
    if(ptr == NULL)
	return false;
    Node* node = *ptr;

    if(node == NULL)
	return false;

    if (value == node->value){
	if(node->left == NULL and node->right == NULL){
	    *ptr = NULL;
	    delete node;
	    return true;
	}

	if(node->left == NULL){
	    *ptr = node->right;
	    delete node;
	    return true;
	}

	if(node->right == NULL){
	    *ptr = node->left;
	    delete node;
	    return true;
	}

	node->value = popMin(&node->right);
	node->updateHeightAndBalance();
	return true;
    }

    bool success = value < node->value ? remove(&node->left, value) : remove(&node->right, value);

    node->updateHeightAndBalance();
    if(node->balance < -1){
	if(node->left->balance >= 1)
	    leftRotation(&node->left);
	rightRotation(ptr);
    }

    if(node->balance > 1){
	if(node->right->balance <= -1)
	    rightRotation(&node->right);
	leftRotation(ptr);
    }

    return success; 
}

bool Tree::remove(int value){
    bool success = remove(&root, value);
    if(success) nodes--;
    return success;
}

bool Tree::insert(int value){
    bool success = insert(&root, value);
    if(success) nodes++;
    return success;
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
    int value = popMin(&root);
    if(value != INT_MAX) nodes--;
    return value; 
}

int Tree::popMax(){
    int value = popMax(&root);
    if(value != INT_MIN) nodes--;
    return value; 
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

int Tree::size(){
    return nodes;
}


