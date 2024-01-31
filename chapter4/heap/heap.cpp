#include "heap.h"

void MinHeap::fixFromDown(int index){
    if(index == 0)
        return;
    int parent_index = (index-1)/2;
    if(heap[index] < heap[parent_index]){
	std::swap(heap[index], heap[parent_index]);
	fixFromDown(parent_index);
    }
}

void MinHeap::fixFromUp(int index){
	int left_child = 2*index+1;
	int right_child = 2*index+2;
	int child_index = -1;

	if(left_child < heap.size()){
		child_index = left_child;
		if(right_child < heap.size() and heap[right_child] < heap[left_child])
			child_index = right_child;
	}

	if(child_index != -1 and heap[child_index] < heap[index]){
		std::swap(heap[child_index], heap[index]);
		fixFromUp(child_index);
	}
}

int MinHeap::getMin(){
    return heap[0];
}

int MinHeap::pop(){
    int value = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    fixFromUp(0);
    return value;
}

void MinHeap::push(int value){
    heap.push_back(value);
    fixFromDown(heap.size()-1);
}
