#ifndef HEAP
#define HEAP

#include <vector>
#include <climits>
#include <algorithm>

class MinHeap {
    private:
        std::vector<int> heap;
        void fixFromDown(int index);
        void fixFromUp(int index);
    public:
        int getMin();
        int pop();
        void push(int value);
};

#endif
