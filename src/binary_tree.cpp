#include "binary_tree.h"
#include <memory>
#include <stdexcept>

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::push(int value) {
    if (!root) {
        root = std::make_shared<Node>(value);
    } else {
        std::shared_ptr<Node> current = root;
        while (true) {
            if (value < current->data) {
                if (!current->left) {
                    current->left = std::make_shared<Node>(value);
                    break;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = std::make_shared<Node>(value);
                    break;
                }
                current = current->right;
            }
        }
    }
}

int BinaryTree::pop() {
    if (!root) {
        throw std::out_of_range("Tree is empty");
    }

    int value = root->data;

    if (!root->left) {
        root = root->right;
    } else if (!root->right) {
        root = root->left;
    } else {
        std::shared_ptr<Node> parent = root;
        std::shared_ptr<Node> successor = root->right;

        while (successor->left) {
            parent = successor;
            successor = successor->left;
        }

        if (parent != root) {
            parent->left = successor->right;
        } else {
            parent->right = successor->right;
        }

        root->data = successor->data;
    }

    return value;
}

bool BinaryTree::search(int value) {
    std::shared_ptr<Node> current = root;

    while (current) {
        if (current->data == value) {
            return true;
        }
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
}
