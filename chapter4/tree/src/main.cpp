#include <iostream>
#include <stdlib.h>
#include <vector>
#include "tree.h"

int main(){
	srand(time(NULL));
	Tree tree;
	std::vector<int> values{10, 5, 2, 7, 6, 8, 15, 12, 16, 17};
	for(int value: values)
	{
		tree.addNode(value);
	}
	std::cout << std::endl;
	std::cout << "InOrder: " << std::endl;
	tree.inOrder(tree.getRoot());
	tree.removeNodeSubtree(9);
	std::cout << "After Deleting Subtree" << std::endl;
	std::cout << "InOrder: " << std::endl;
	tree.inOrder(tree.getRoot());

}
