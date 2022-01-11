#include <iostream>
#include "utils.h"
#include "Sorter.h"
#include <chrono>
#include <unistd.h>

using namespace std;

bool compareInt(int a, int b){
    return a > b;
}

bool compareFloat(float a, float b){
    return a > b;
}

void timeTest(sequence<int> *input){
    using namespace chrono;
    auto *forMerge = input->getSubsequence(0, input->length());
    auto *forQuick = input->getSubsequence(0, input->length());
    auto *forShell = input->getSubsequence(0, input->length());

    cout << "Sorting array: " << endl;
    printSequence(*input);

    auto begin1 = high_resolution_clock::now();
    Mergesort<int>(forMerge, &compareInt);
    auto end1 = high_resolution_clock::now();
    auto time1 = duration_cast<microseconds>(end1 - begin1);
    cout << "Merge sort complete in " << time1.count() << " mcs" << endl;
    printSequence(*forMerge);


    sleep(1);

    auto begin2 = high_resolution_clock::now();
    Quicksort<int>(forQuick, &compareInt);
    auto end2 = high_resolution_clock::now();
    auto time2 = duration_cast<microseconds>(end2 - begin2);
    cout << "Quick sort complete in " << time2.count() << " mcs" << endl;
    printSequence(*forQuick);


    sleep(1);

    auto begin3 = high_resolution_clock::now();
    Shellsort<int>(forShell, &compareInt);
    auto end3 = high_resolution_clock::now();
    auto time3 = duration_cast<microseconds>(end3 - begin3);
    cout << "Shell sort complete in " << time3.count() << " mcs" << endl;
    printSequence(*forShell);

}

int main() {
    int seqPrompt;
    cout << "~~~~~~~~~~MENU~~~~~~~~~~" << endl;
    cout << "1. Linked list based sequence" << endl;
    cout << "2. Dynamic array based sequence" << endl;
    while(true) {
        cout << "Enter (1-2):  ";
        cin >> seqPrompt;

        if (seqPrompt == 1) {
            cout << "~~~~~~~~~~Linked list~~~~~~~~~~" << endl;
            break;
        }
        else if (seqPrompt == 2) {
            cout << "~~~~~~~~~~Dynamic array~~~~~~~~~~" << endl;
            break;
        }
    }
    cout << "1. Enter values" << endl;
    cout << "2. automatically generate values" << endl;
    int fillPrompt;
    while(true) {
        cout << "Enter (1-2): ";
        cin >> fillPrompt;
        if (fillPrompt < 3 && fillPrompt > 0) {
            cout << "Enter size of sequence:  " << endl;
            break;
        }
    }
    int size;
    cin >> size;
    if(fillPrompt == 1){
        int t;
        int arr[size];
        for(int i = 0; i < size; i++){
            cin >> t;
            arr[i] = t;
        }
        if(seqPrompt == 1){
            auto *seq = new listSequence<int>(arr, size);
            timeTest(seq);
        }
        if(seqPrompt == 2){
            auto *seq = new arraySequence<int>(arr, size);
            timeTest(seq);
        }
    }
    if(fillPrompt == 2){
        if(seqPrompt == 1){
            auto *seq = generateRandomListSequenceInt<int>(size);
            timeTest(seq);
        }
        if(seqPrompt == 2){
            auto *seq = generateRandomArraySequenceInt<int>(size);
            timeTest(seq);
        }
    }
    cout << "" << endl;
    cout << "" << endl;
    return 0;
}
