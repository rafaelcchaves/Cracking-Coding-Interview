#ifndef HEAP
#define HEAP

#include <vector>
#include <climits>
#include <algorithm>

class MinHeap {
    private:
        std::vector<int> heap;
        void fixFromDown(int index);
        void fixFromTop(int index);
    public:
	MinHeap();
        int top();
        int pop();
	int size();
        void push(int value);
};

#endif
