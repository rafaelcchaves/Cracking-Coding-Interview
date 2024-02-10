#include <iostream>
#include <stdlib.h>
#include <vector>
#include "tree.h"

int main(int argc, char* argv[]){
	int size = 16;
	if(argc == 2)
	   size = atoi(argv[1]);
	srand(time(NULL));
	Tree tree;
	//std::vector<int> values{10, 5, 2, 7, 6, 8, 15, 12, 16, 17};
	//std::cout << "Initial Values: ";
	for(int value = 1; value <= size; value++){
	    std::cout << value << ' ';
	    tree.insert(value);
	}
	while(tree.size()){
	    std::cout << "InOrder: " << std::endl;
	    tree.inOrder(tree.root);
	    std::cout << std::endl;
	    tree.popMax();
	}
}
