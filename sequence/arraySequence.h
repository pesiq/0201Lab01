//
// Created by pesel on 28.05.2021.
//

#ifndef LAB02_ARRAYSEQUENCE_H
#define LAB02_ARRAYSEQUENCE_H

#include "../lower/dynamicArray.h"
#include "../lower/dynamicArray.cpp"
#include "sequence.h"

template<class T>
class arraySequence : public sequence<T> {
private:
    dynamicArray<T> array;
public:

    arraySequence() : array(){}

    arraySequence(T* arr, int amount) : array(arr, amount){}

    explicit arraySequence(int amount){
        array = dynamicArray<T> (amount);
    }

    arraySequence(dynamicArray<T> const &arr){
        array = arr;
    }

    ~arraySequence(){
        array.deleteArray();
    }

    void deleteSequence(){
        array.deleteArray();
    }

    T getFirst(){
        return array.get(0);
    }

    T getLast(){
        return array.get(array.length()-1);
    }

    T get(int index){
        return array.get(index);
    }

    void insertAt(T item, int index){
        if (index > 0){
            array.resize(1);
            for (int i = array.length()-2; i >= index; i--) {
                array[i+1] = array[i];
            }
            array[index] = item;
        }
    }

    int length(){
        return array.length();
    }

    void append(T item){
        array.append(item);
    }

    void prepend(T item){
        array.prepend(item);
    }

    void set(T item, int index){
        array.set(index, item);
    }

    void resize(int amount){ // enter delta of dimensions positive to increase, negative to decrease
        array.resize(amount);
    }

    void concatenate(sequence<T>* list){
        array.resize(list->length());
        for (int i = array.length(), j = 0; i < list->length(); i++, j++) {
            array.set(i, list->get(j));
        }
    }

    sequence<T>* getSubsequence(int start, int end){
        arraySequence<T> *result = new arraySequence<T>(end - start + 1);
        for(int i = start, j = 0; i < end; i++, j++){
            result->set(j, array.get(i));
        }
        return result;
    }

    T& operator[] (int index){
        return array[index];
    }


};

#endif //LAB02_ARRAYSEQUENCE_H
