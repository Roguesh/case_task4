#include "gtest/gtest.h"
#include "queue.h"
#include "heap.h"
#include <chrono>
#include <iostream>
#include <climits>

TEST(PerformanceTest, QueueLargeData) {
    Queue q;
    const int N = 100000;

    // Измерение времени добавления элементов
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < N; ++i) {
        q.push(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Queue push time: " << elapsed_seconds.count() << "s\n";

    EXPECT_EQ(q.size(), N);

    // Измерение времени удаления элементов
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < N; ++i) {
        q.pop();
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Queue pop time: " << elapsed_seconds.count() << "s\n";

    EXPECT_EQ(q.size(), 0);
}

TEST(PerformanceTest, HeapLargeData) {
    Heap h;
    const int N = 100000;

    // Измерение времени добавления элементов
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < N; ++i) {
        h.push(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Heap push time: " << elapsed_seconds.count() << "s\n";

    // Измерение времени удаления элементов
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < N; ++i) {
        h.pop();
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Heap pop time: " << elapsed_seconds.count() << "s\n";
}

TEST(PerformanceTest, StressTest) {
    Queue q;
    Heap h;
    const int N = 100000;

    // Стресс-тест для очереди
    for(int i = 0; i < N; ++i) {
        q.push(i);
        h.push(i);
    }

    // Проверка размеров
    EXPECT_EQ(q.size(), N);
    EXPECT_EQ(h.size(), N);

    // Очистка структур
    for(int i = 0; i < N; ++i) {
        q.pop();
        h.pop();
    }

    EXPECT_EQ(q.size(), 0);
    EXPECT_EQ(h.size(), 0);
}

