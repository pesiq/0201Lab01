#include "utils.h"
#include "Sorter.h"

#include <unistd.h>

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


void testShellsort(int size){
    auto seq1 = generateRandomArraySequenceInt<int>(size);
    printSequence(*seq1);
    Shellsort(seq1, &compareInt);
    printSequence(*seq1);

    auto seq2 = generateRandomListSequenceInt<int>(size);
    printSequence(*seq2);
    Shellsort(seq2, &compareInt);
    printSequence(*seq2);
}


int main(){
    //testUtilsGen();
    testShellsort(30);
}