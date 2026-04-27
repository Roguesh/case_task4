#include "gtest/gtest.h"
#include "binary_tree.h"
#include <climits>  // Добавляем это включение

TEST(BinaryTreeTest, BasicOperations) {
    BinaryTree tree;
    tree.push(5);
    tree.push(10);
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(10));
    EXPECT_FALSE(tree.search(15));
}

TEST(BinaryTreeTest, SearchTest) {
    BinaryTree tree;
    tree.push(1);
    tree.push(2);
    tree.push(3);
    EXPECT_TRUE(tree.search(2));
    EXPECT_FALSE(tree.search(4));
}

TEST(BinaryTreeTest, PopTest) {
    BinaryTree tree;
    tree.push(1);
    tree.push(2);
    EXPECT_EQ(tree.pop(), 1);
    EXPECT_EQ(tree.pop(), 2);
}

TEST(BinaryTreeTest, EdgeCases) {
    BinaryTree tree;
    EXPECT_THROW(tree.pop(), std::out_of_range);
    tree.push(1);
    EXPECT_EQ(tree.pop(), 1);
    EXPECT_THROW(tree.pop(), std::out_of_range);
}

TEST(BinaryTreeTest, DuplicateValues) {
    BinaryTree tree;
    tree.push(5);
    tree.push(5);
    tree.push(5);
    EXPECT_TRUE(tree.search(5));
    EXPECT_EQ(tree.pop(), 5);
    EXPECT_EQ(tree.pop(), 5);
    EXPECT_EQ(tree.pop(), 5);
}

TEST(BinaryTreeTest, LargeValues) {
    BinaryTree tree;
    tree.push(INT_MAX);
    tree.push(INT_MIN);
    EXPECT_TRUE(tree.search(INT_MAX));
    EXPECT_TRUE(tree.search(INT_MIN));
    EXPECT_EQ(tree.pop(), INT_MAX);
    EXPECT_EQ(tree.pop(), INT_MIN);
}
