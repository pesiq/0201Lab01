//
// Created by pesel on 12.11.2021.
//

#ifndef LAB1_SORTER_H
#define LAB1_SORTER_H

#include "sequence/sequence.h"

//cmp is true when a > b

template<typename T>
void Quicksort(sequence<T> *input, bool (*cmp)(T a, T b), int left = 0, int right = 0, int rec = 0){
    if(rec == 0){
        left = 0;
        right = input->length()-1;
    }
    rec++;

    int i = left;
    int j = right;
    //set pivot in the centre of partition
    T pivot = input->get((i + j) / 2);

    //find elements in wrong partitions and swap
    while (i <= j){
        while(cmp(pivot, input->get(i))){
            i++;
        }
        while(cmp(input->get(j), pivot)){
            j--;
        }

        //if found swap elements
        if(i <= j) {
            T temp = input->get(i);
            input->set(input->get(j), i);
            input->set(temp, j);
            i++;
            j--;
        }
    }
    //print(*input);
    //recurse
    if(j > left){
        Quicksort(input, cmp, left, j, rec);
    }
    if(i < right){
        Quicksort(input, cmp, i, right, rec);

    }

}

template<typename T>
void merge(sequence<T> *input, bool (*cmp)(T a, T b), int left, int middle, int right){

    int sizeLeft = middle - left + 1; //size of left subarray
    int sizeRight = right - middle; //size of right subarray

    auto *subL = input->getSubsequence(left, left+sizeLeft);
    auto *subR = input->getSubsequence(middle+1, middle+sizeRight + 1);

    //iterators
    int i = 0;
    int j = 0;
    unsigned int k = left;

    //merge sub arrays to real one
    while(i<sizeLeft && j < sizeRight){
        if(!cmp(subL->get(i), subR->get(j))){
            input->set(subL->get(i), k);
            i++;
        } else {
            input->set(subR->get(j), k);
            j++;
        }
        k++;
    }

    //account for extras in subarrays

    while (i < sizeLeft){
        input->set(subL->get(i), k);
        i++;
        k++;
    }

    while (j < sizeRight){
        input->set(subR->get(j), k);
        j++;
        k++;
    }


}

template<typename T>
void Mergesort(sequence<T> *input, bool (*cmp)(T a, T b), int left = 0, int right = 0, int rec = 0){
    if(rec == 0){
        left = 0;
        right = input->length()-1;
    }
    rec++;
    //auto *array = input->getSubsequence();
    int middle;
    if(left < right){
        middle = left+(right-left)/2;
        Mergesort(input, cmp, left, middle, rec);
        Mergesort(input, cmp, middle + 1, right, rec);
        merge(input, cmp, left, middle, right);
    }

}


template<typename T>
void Shellsort(sequence<T> *input, bool (*cmp)(T a, T b)){
    for (int gap = input->length() / 2; gap > 0; gap /=2){
        for(int i = gap; i < input->length(); i++){
            T temp = input->get(i);
            int j;
            for(j = i; j >= gap && cmp(input->get(j - gap), temp); j -= gap){
                input->set(input->get(j - gap), j);
            }
            input->set(temp, j) ;
        }
    }
}


#endif //LAB1_SORTER_H
