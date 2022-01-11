//
// Created by pesel on 12.11.2021.
//

#ifndef LAB1_SORTER_H
#define LAB1_SORTER_H

#include "sequence/sequence.h"

template<typename T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

//cmp is true when a > b

template<typename T>
sequence<T> *partition(){

}


template<typename T>
sequence<T>* Quicksort(sequence<T> input, bool (*cmp)(T a, T b)){

}

template<typename T>
sequence<T> *merge(sequence<T> *input, bool (*cmp)(T a, T b), unsigned int left, unsigned int middle, unsigned int right){

}

template<typename T>
sequence<T>* Mergesort(sequence<T> input, bool (*cmp)(T a, T b), unsigned int left, unsigned int right){

}


template<typename T>
sequence<T>* Shellsort(sequence<T> *array, bool (*cmp)(T a, T b)){

    for (int gap = array->length() / 2; gap > 0; gap /=2){
        for(int i = gap; i < array->length(); i++){
            T temp = array->get(i);
            int j;
            for(j = i; j >= gap && cmp(array->get(j - gap), temp); j -= gap){
                array->set(array->get(j-gap), j);
            }
            array->set(temp,j) ;
        }
    }
    return array;
}


#endif //LAB1_SORTER_H
