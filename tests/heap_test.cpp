#include "gtest/gtest.h"
#include "heap.h"

TEST(HeapTest, BasicOperations) {
    Heap h;
    h.push(5);
    h.push(3);
    h.push(8);
    h.push(1);

    EXPECT_EQ(h.pop(), 8);
    EXPECT_EQ(h.pop(), 5);
    EXPECT_EQ(h.pop(), 3);
    EXPECT_EQ(h.pop(), 1);
}

TEST(HeapTest, EdgeCases) {
    Heap h;

    h.push(10);
    EXPECT_EQ(h.pop(), 10);

    h.push(20);
    h.push(15);
    EXPECT_EQ(h.pop(), 20);
    EXPECT_EQ(h.pop(), 15);
}

TEST(HeapTest, MultipleElements) {
    Heap h;
    int arr[] = {4, 10, 3, 5, 1};

    for(int i = 0; i < 5; ++i) {
        h.push(arr[i]);
    }

    int expected[] = {10, 5, 4, 3, 1};
    for(int i = 0; i < 5; ++i) {
        EXPECT_EQ(h.pop(), expected[i]);
    }
}
