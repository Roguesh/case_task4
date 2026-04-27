#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <stdexcept>

class Queue {
private:
    std::vector<int> data;
public:
    void push(int value);
    int pop();
    bool isEmpty();
    int size();
};

#endif
