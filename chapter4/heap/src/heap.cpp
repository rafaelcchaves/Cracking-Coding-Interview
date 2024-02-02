#include "heap.h"

MinHeap::MinHeap(){}

void MinHeap::fixFromDown(int index){
    if(index == 0)
        return;
    int parent_index = (index-1)/2;
    if(heap[index] < heap[parent_index]){
	std::swap(heap[index], heap[parent_index]);
	fixFromDown(parent_index);
    }
}

void MinHeap::fixFromTop(int index){
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
		fixFromTop(child_index);
	}
}

int MinHeap::top(){
    return heap[0];
}

int MinHeap::pop(){
    int value = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    fixFromTop(0);
    return value;
}

int MinHeap::size(){
    return heap.size();	
}

void MinHeap::push(int value){
    heap.push_back(value);
    fixFromDown(heap.size()-1);
}
