#include "dynamicArray.h"

//constructors
template<class T>
dynamicArray<T>::dynamicArray(T *arr, size_t amount) {
    bufferSize = 2*amount;
    items = new T[bufferSize];
    size = amount;
    for(int i = 0; i < amount; i++){
        items[i] = arr[i];
    }
}

template<class T>
dynamicArray<T>::dynamicArray(size_t amount) {
    if(amount <= 0) {
        throw invalidArgument();
    }
    size = amount;
    bufferSize = 2*amount;
    items = new T[bufferSize]; //allocating memory for dynamicArray
}

template<class T>
dynamicArray<T>::dynamicArray(const dynamicArray<T> &array) {
    bufferSize = array.bufferSize;
    items = new T[bufferSize];
    size = array.size;
    for(int i = 0; i < array.size; i++){
        items[i] = array.items[i];
    }
}

template<class T>
dynamicArray<T>::dynamicArray() {
    size = 0;
    bufferSize = 10;
    items = new T[bufferSize];
}

//destructors
template<class T>
dynamicArray<T>::~dynamicArray() {
    if(bufferSize > 0)
        delete[] items;
    bufferSize = 0;
    size = 0;
}

template<class T>
void dynamicArray<T>::deleteArray(){
    if(bufferSize > 0)
        delete[] items;
    bufferSize = 0;
    size = 0;
}

//decomposition
template <class T>
T dynamicArray<T>::get(int index) {
    if(index > size || index < 0){
        throw indexOutOfRange();
    }
    return items[index];
}

template<class T>
void dynamicArray<T>::append(T value){
    size++;
    if (size > bufferSize){
        resize(bufferSize*2);
    }
    set(size-1, value);
}

template<class T>
void dynamicArray<T>::prepend(T value){
    size++;
    if (size > bufferSize){
        resize(bufferSize*2);
    }
    for(int i = size-2; i > 0; i--) {
        items[i+1] = items[i];
    }
    set(0, value);
}

template<class T>
size_t dynamicArray<T>::length() {
    return size;
}

//operations
template<class T>
void dynamicArray<T>::set(int index, T value) {
    if(index > size || index < 0){
        throw indexOutOfRange();
    }
    items[index] = value;
}

template<class T>
void dynamicArray<T>::resize(int amount) {

    if(amount == 0){
        return;
    }

    if (amount > 0){
        size += amount;
        if(size > bufferSize){
            T* temp = new T[size+(amount * 2)];
            bufferSize += amount * 2;
            for(int i = 0; i<size-amount; i++){
                temp[i] = items[i];
            }
            delete[] items;
            items = temp;
        }
        return;
    }

    if(amount < 0){
        if(size-amount > 0){
            size += amount;
        } else {
            size = 0;
        }
        return;
    }
}

