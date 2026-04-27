#include "heap.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

void Heap::heapify(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < data.size() && data[left] > data[largest]) {
        largest = left;
    }
    if (right < data.size() && data[right] > data[largest]) {
        largest = right;
    }
    if (largest != index) {
        std::swap(data[index], data[largest]);
        heapify(largest);
    }
}

void Heap::push(int value) {
    data.push_back(value);
    int index = data.size() - 1;
    while (index != 0 && data[(index - 1) / 2] < data[index]) {
        std::swap(data[index], data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int Heap::pop() {
    if (data.empty()) {
        throw std::out_of_range("Heap is empty");
    }
    int root = data[0];
    data[0] = data.back();
    data.pop_back();
    heapify(0);
    return root;
}
