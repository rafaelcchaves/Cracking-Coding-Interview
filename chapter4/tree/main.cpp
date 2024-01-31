#include <iostream>
#include <stdlib.h>

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

class Tree {
	private:
		Node *root;
	public:
		Tree(): root(NULL) {};
		void addNode(int value);
		void addNode(Node* node);
		void inOrder(Node* node);
		void preOrder(Node* node);
		void postOrder(Node* node);
		void visit(Node* node);
		Node* getRoot();
};

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


int main(){
	srand(time(NULL));
	Tree tree;
	for(int i = 0; i < 10; i++){
  		int num = rand()%50;
		tree.addNode(num);
		std::cout << num << ' ';
	}
	std::cout << std::endl;
	std::cout << "InOrder: " << std::endl;
	tree.inOrder(tree.getRoot());
	std::cout << "PreOrder: " << std::endl;
	tree.preOrder(tree.getRoot());
	std::cout << "postOrder: " << std::endl;
	tree.postOrder(tree.getRoot());
}

int Node::getValue(){
	return value;
}

bool Node::addLeft(Node *children){
	if(left != NULL) return false;
	left = children; return true;
}

bool Node::removeLeft(){
	if(left != NULL) return false;
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
	if(right != NULL) return false;
	right = NULL; return true;
}

Node* Node::getRight(){
	return right;
}





