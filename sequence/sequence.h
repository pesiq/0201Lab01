//
// Created by pesel on 27.05.2021.
//

#include <cstdlib>
#include <ostream>

#ifndef LAB02_SEQUENCE_H
#define LAB02_SEQUENCE_H

template<class T>
class sequence{
public:
    virtual T getFirst() = 0;
    virtual T getLast() = 0;
    virtual T get(int index) = 0;
    //virtual sequence<T>* getSubsequence(int start, int end) = 0;
    virtual int length() = 0;
    virtual void set(T item, int index) = 0;
    virtual void append(T item) = 0;
    virtual void prepend(T item) = 0;
    virtual void insertAt(T item, int index) = 0;
    virtual void concatenate(sequence<T>* list) = 0;
};

#endif //LAB02_SEQUENCE_H
