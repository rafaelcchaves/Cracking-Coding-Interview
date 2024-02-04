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
		tree.insert(value);
	}
	std::cout << std::endl;
	std::cout << "InOrder: " << std::endl;
	tree.inOrder(tree.root);
	std::cout << "Min and Max: " << std::endl;
	std::cout << tree.findMin() << ' ' << tree.findMax() << std::endl;
	std::cout << "Successfull remove? ";
	std::cout << (tree.remove(5)?"TRUE":"FALSE") << std::endl;
	std::cout << "After Deleting Subtree" << std::endl;
	std::cout << "InOrder: " << std::endl;
	tree.inOrder(tree.root);
	std::cout << "Min and Max: " << std::endl;
	std::cout << tree.findMin() << ' ' << tree.findMax() << std::endl;

}
