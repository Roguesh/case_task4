cmake_minimum_required(VERSION 3.10)
project(CBMO_TESTS)

include_directories(${CMAKE_SOURCE_DIR}/src)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(src SHARED
    src/queue.cpp
    src/heap.cpp
    src/binary_tree.cpp
)

add_executable(runTests
    tests/queue_test.cpp
    tests/heap_test.cpp
    tests/performance_test.cpp
    tests/negative_test.cpp
    tests/main.cpp
    tests/binary_tree_test.cpp
)

target_link_libraries(runTests
    src
    ${GTEST_LIBRARIES}
    pthread
    stdc++fs  # Для файловой системы
    stdc++    # Основная C++ библиотека
)
