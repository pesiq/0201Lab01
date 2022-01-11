#include "utils.h"
#include "Sorter.h"

#include <unistd.h>
#include <cassert>

bool compareInt(int a, int b){
    return a > b;
}

bool compareFloat(float a, float b){
    return a > b;
}



void testUtilsGen(){

    auto seq1 = generateRandomArraySequenceInt<int>(20);
    printSequence(*seq1);

    auto seq2 = generateRandomListSequenceInt<int>(20);
    printSequence(*seq2);
}

template<typename T>
void testSorting(sequence<T> &input){
        for(int i = 1; i < input.length(); i++){
            assert(input.get(i) >= input.get(i-1));
        }
}


void testShellsort(int size){
    std::cout << "shellsort array" << std::endl;
    auto seq1 = generateRandomArraySequenceInt<int>(size);
    printSequence(*seq1);
    Shellsort(seq1, &compareInt);
    testSorting(*seq1);
    printSequence(*seq1);

    std::cout << "shellsort list" << std::endl;
    auto seq2 = generateRandomListSequenceInt<int>(size);
    printSequence(*seq2);
    Shellsort(seq2, &compareInt);
    testSorting(*seq2);
    printSequence(*seq2);
}

void testMergesort(int size){
    std::cout << "mergesort array" << std::endl;
    auto seq1 = generateRandomArraySequenceInt<int>(size);
    printSequence(*seq1);
    Mergesort(seq1, &compareInt);
    printSequence(*seq1);
    testSorting(*seq1);


    std::cout << "mergesort list" << std::endl;
    auto seq2 = generateRandomListSequenceInt<int>(size);
    printSequence(*seq2);
    Mergesort(seq2, &compareInt);
    printSequence(*seq2);
    testSorting(*seq2);

}


int main(){
    int size = 21;
    testUtilsGen();
    testShellsort(size);
    testMergesort(size);
}