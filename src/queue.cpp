#include "queue.h"
#include <vector>
#include <stdexcept>

void Queue::push(int value) {
    data.push_back(value);
}

int Queue::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    int value = data.front();
    data.erase(data.begin());
    return value;
}

bool Queue::isEmpty() {
    return data.empty();
}

int Queue::size() {
    return data.size();
}
