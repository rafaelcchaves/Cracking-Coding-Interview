#include <iostream>
#include <stdlib.h>
#include <vector>
#include "tree.h"

int main(int argc, char* argv[]){
	int remove_number = 5;
	if(argc == 2)
	   remove_number = atoi(argv[1]);
	srand(time(NULL));
	Tree tree;
	std::vector<int> values{10, 5, 2, 7, 6, 8, 15, 12, 16, 17};
	for(int value: values)
		tree.insert(value);
	std::cout << std::endl;
	std::cout << "InOrder: " << std::endl;
	tree.inOrder(tree.root);
	std::cout << "Min and Max: " << std::endl;
	std::cout << tree.findMin() << ' ' << tree.findMax() << std::endl;
	std::cout << "Successfull remove?";
	std::cout << (tree.remove(remove_number)?"TRUE":"FALSE") << std::endl;
	std::cout << "After Deleting Subtree" << std::endl;
	tree.popMin();
	tree.popMax();
	std::cout << "InOrder: " << std::endl;
	tree.inOrder(tree.root);
	std::cout << "Min and Max: " << std::endl;
	std::cout << tree.findMin() << ' ' << tree.findMax() << std::endl;

}
