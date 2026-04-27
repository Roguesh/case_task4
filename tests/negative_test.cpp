#include "gtest/gtest.h"
#include "queue.h"
#include "heap.h"
#include <climits>

TEST(NegativeTest, QueueEmptyOperations) {
    Queue q;
    EXPECT_THROW(q.pop(), std::out_of_range);
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(NegativeTest, HeapEmptyOperations) {
    Heap h;
    EXPECT_THROW(h.pop(), std::out_of_range);
    EXPECT_EQ(h.size(), 0);
}

TEST(NegativeTest, QueueBoundaryValues) {
    Queue q;
    q.push(INT_MAX);
    q.push(INT_MIN);
    EXPECT_EQ(q.pop(), INT_MAX);
    EXPECT_EQ(q.pop(), INT_MIN);
}

TEST(NegativeTest, HeapBoundaryValues) {
    Heap h;
    h.push(INT_MAX);
    h.push(INT_MIN);
    EXPECT_EQ(h.pop(), INT_MAX);
    EXPECT_EQ(h.pop(), INT_MIN);
}

TEST(NegativeTest, DuplicateValues) {
    Queue q;
    q.push(5);
    q.push(5);
    q.push(5);
    EXPECT_EQ(q.pop(), 5);
    EXPECT_EQ(q.pop(), 5);
    EXPECT_EQ(q.pop(), 5);
}
