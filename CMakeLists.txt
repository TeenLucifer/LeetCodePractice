cmake_minimum_required(VERSION 3.20)
project(dataStructure)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        include
)

add_executable(
        dataStructure
        src/main.cpp
        src/MultiQuestions.cpp
        src/t-rex.cpp
        src/MyHashTable.cpp
        src/MinStack.cpp
        src/AVL.cpp
        src/RedBlackTree.cpp
        src/BaiDuTest.cpp include/BaiDuTest.h src/HuaWeiTest.cpp include/HuaWeiTest.h src/MeiTuanTest.cpp include/MeiTuanTest.h)