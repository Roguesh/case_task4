#include "gtest/gtest.h"
#include "queue.h"

TEST(QueueTest, BasicOperations) {
    Queue q;
    q.push(1);
    q.push(2);
    EXPECT_EQ(q.pop(), 1);
    EXPECT_EQ(q.pop(), 2);
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(QueueTest, EdgeCases) {
    Queue q;
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);

    q.push(10);
    EXPECT_FALSE(q.isEmpty());
    EXPECT_EQ(q.size(), 1);

    q.pop();
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(QueueTest, MultipleElements) {
    Queue q;
    for(int i = 0; i < 10; ++i) {
        q.push(i);
    }

    for(int i = 0; i < 10; ++i) {
        EXPECT_EQ(q.pop(), i);
    }

    EXPECT_TRUE(q.isEmpty());
}
