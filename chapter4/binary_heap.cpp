#include <vector>
#include <climits>

class MinHeap {
    private:
        std::vector<int> heap;
        void fixingFromDown(int index);
        void fixingFromUp(int index);
    public:
        int getMin();
        int pop();
        void push(int value);
};

void MinHeap::fixingFromDown(int index){
    if(index == 0)
        return;
    if(heap[index] < heap[index/2-1])
}

int MinHeap::getMin(){
    return heap[0];
}

int MinHeap::pop(){
    int value = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    fixingFromUp(0);
    return value;
}

void MinHeap::push(int value){
    heap.push_back(value);
    fixingFromDown(heap.size()-1);
}

int main(){
   
}