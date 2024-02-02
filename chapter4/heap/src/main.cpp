#include "heap.h"
#include <iostream>
#include <iomanip>

int main(){
    MinHeap heap;
    std::vector<int> values{1,-2,3,-5, 10};
    for(int i: values){
	heap.push(i);
	std::cout <<"Last inserted value: " << std::setw(5) << i << ", Current top: " << std::setw(5) <<  heap.top() << std::endl;
    }
    while(heap.size()){
	std::cout << "Heap size: " << std::setw(5) << heap.size() << ", Current top: " << std::setw(5) << heap.pop() << std::endl;
    }
	
}


