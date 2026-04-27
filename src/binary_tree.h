#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <memory>

class BinaryTree {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

public:
    BinaryTree();
    void push(int value);
    int pop();
    bool search(int value);
};

#endif // BINARY_TREE_H
