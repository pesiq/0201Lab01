
#ifndef LAB1_UTILS_H
#define LAB1_UTILS_H

#include <ctime>
#include <iostream>
#include "sequence/sequence.h"
#include "sequence/arraySequence.h"
#include "sequence/listSequence.h"


template<typename T>
void printSequence(sequence<T> &input){
    for(int i = 0; i < input.length(); i++){
        std::cout << input.get(i) << " ";
    }
    std::cout << std::endl;
}

int* intArray(int size){
    std::srand(std::time(nullptr));
    int* arr = new int[size];
    for(int i = 0; i<size; i++){
        arr[i] = rand()%1000;
    }
    return arr;
}

template<typename T>
sequence<T> *generateRandomArraySequenceInt(int size){
    auto *result = new arraySequence<T>(intArray(size), size);
    return result;
}

template<typename T>
sequence<T> *generateRandomListSequenceInt(int size){
    auto *result = new listSequence<T>(intArray(size), size);
    return result;
}

#endif //LAB1_UTILS_H
