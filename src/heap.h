#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap {
private:
    std::vector<int> data;
    void heapify(int index);
public:
    void push(int value);
    int pop();
    int size() const { return data.size(); }
};

#endif // HEAP_H
