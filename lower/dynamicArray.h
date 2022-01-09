#include <cstdlib>
#include "../exceptions/exceptions.h"
#ifndef LAB02_ARRAY_H
#define LAB02_ARRAY_H

template <class T>
class dynamicArray{
private:
    T *items;
    size_t size;
    size_t bufferSize;
    const size_t elementSize = sizeof(T);

public:
    //array creation
    dynamicArray(T* arr, size_t amount); //create array from static
    explicit dynamicArray(size_t amount); //create empty buffer
    dynamicArray(dynamicArray<T> const &array);// copy existing array
    dynamicArray();

    //array destruction
    ~dynamicArray(); //destructor
    void deleteArray(); //deletion function

    //decomposition
    T get(int index); //get element at index
    size_t length(); //get size of array

    //operations
    void set(int index, T value); //set element at index
    void append(T value);
    void prepend(T value);
    //change size of array
    //negative value to reduce
    //positive value to increase
    void resize(int amount);

    T& operator[](int index){
        if(index >= 0 && index < size)
            return items[index];
        if(index < 0 && index > -size)
            return items[size-index];
        else{
            throw indexOutOfRange();
        }
    }

    dynamicArray<T>& operator= (const dynamicArray<T>& array){
        bufferSize = array.bufferSize;
        items = new T[bufferSize];
        size = array.size;
        if(array.items == nullptr) {
            items = nullptr;
            return *this;
        }
        for(int i = 0; i < array.size; i++){
            items[i] = array.items[i];
        }
        return *this;
    }

};



#endif //LAB02_ARRAY_H
