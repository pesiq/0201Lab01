cmake_minimum_required(VERSION 3.19)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)



add_executable(Lab01 Sorter.h Sorters.cpp main.cpp lower/dynamicArray.h lower/dynamicArray.cpp lower/linkedList.cpp lower/linkedList.h sequence/sequence.h sequence/listSequence.h sequence/arraySequence.h higher/Vector.h higher/Set.h)
add_executable(test Sorter.h Sorters.cpp tests.cpp lower/dynamicArray.h lower/dynamicArray.cpp lower/linkedList.cpp lower/linkedList.h)