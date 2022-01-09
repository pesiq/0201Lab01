//
// Created by pesel on 04.05.2021.
//

#include "linkedList.h"

template<class T>
void linkedList<T>::append(T val) {
    size++;
    auto *temp = new struct item;
    temp->value = val;
    temp->next = nullptr;
    temp->previous = last;
    if(first == nullptr){
        first = temp;
    }
    if(last != nullptr){
        last->next = temp;
    }
    last = temp;
}

template<class T>
void linkedList<T>::prepend(T val) {
    size++;
    auto *temp = new struct item;
    temp->value = val;
    temp->previous = nullptr;
    temp->next = first;
    if(last == nullptr){
        last = temp;
    }
    if(first != nullptr){
        first->previous = temp;
    }
    first = temp;
}

template<class T>
void linkedList<T>::set(T val, int index){
    if(abs(index) > size){
        throw indexOutOfRange();
    }

    if(size == 0){
        first->value = val;
        return;
    }
    if(index > 0){
        struct item *ptr = first;
        while(index){
            ptr = ptr->next;
            index--;
        }
        ptr->value = val;
    } else {
        struct item *ptr = first;
        while (index){
            ptr = ptr->previous;
            index++;
        }
        ptr->value = val;
    }
}

template<class T>
void linkedList<T>::insertAt(T val, int index) {

    if(abs(index) > size){
        throw indexOutOfRange();
    }

    if(index == 0){
        prepend(val);
        return;
    }
    if(index == size-1){
        append(val);
        return;
    }

    struct item *ptr = first;
    auto *newItem = new struct item;
    newItem->value = val;

    if(size == 0){
        newItem->next = nullptr;
        newItem->previous = nullptr;
        first = newItem;
        last = newItem;
        size++;
        return;
    }
    if(index > 0){
        while(index>0){
            ptr = ptr->next;
            index--;
        }
        newItem->previous = ptr->previous;
        ptr->previous = newItem;
        newItem->previous->next = newItem;
        newItem->next = ptr;

    } else {
        while (index<0){
            ptr = ptr->previous;
            index++;
        }
        newItem->previous = ptr->previous;
        ptr->previous = newItem;
        newItem->previous->next = newItem;
        newItem->next = ptr;
    }
    size++;
}

template<class T>
linkedList<T>& linkedList<T>::getSublist(size_t start, size_t end) {
    size_t resultSize = end - start + 1;
    T *array = new T[resultSize];
    struct item *ptr = first;
    for (int i = 0; i < start; i++){
        ptr = ptr->next;
    }
    for (int i = 0; i < resultSize; i++){
        array[i] = ptr->value;
        ptr = ptr->next;
    }
    auto *res = new linkedList<T>(array, resultSize);
    return *res;
}

template<class T>
T &linkedList<T>::get(int index) {
    if(index > size || index < 0){
        throw indexOutOfRange();
    }
    T temp;
    struct item *ptr = first;
    for(int i = 0; i < index; i++){
        ptr = ptr->next;
    }
    return ptr->value;
}

template<class T>
T linkedList<T>::getFirst() {
    if(first == nullptr) {
        throw indexOutOfRange();
    }
    return first->value;
}

template<class T>
T linkedList<T>::getLast() {
    if(last == nullptr) {
        throw indexOutOfRange();
    }
    return last->value;
}

template<class T>
int linkedList<T>::length(){
    return size;
}

template<class T>
void linkedList<T>::concatenate(linkedList<T> list) {
    struct item *ptr = list.first;
    for (int i = 0; i < list.size; i++) {
        append(ptr->value);
        ptr->next;
    }
}


template<class T>
linkedList<T>::~linkedList(){
    if(size != 0)
        deleteList();
    first == nullptr;
    last == nullptr;
    size = 0;
}

template<class T>
void linkedList<T>::deleteList() {
    if(first != nullptr) {
        struct item *curr = first;
        struct item *next = curr->next;
        while (curr != nullptr){
            delete curr;
            curr = next;
            if(curr)
                next = curr->next;

        }
        size = 0;
    }
}


template<class T>
void linkedList<T>::deleteItem(int index) {
    if(abs(index) > size){
        throw indexOutOfRange();
    }
    if(index == 0){
        first->next->previous = nullptr;
        auto *temp = first->next;
        delete first;
        first = temp;
    }
    if(index == size-1){
        last->previous->next = nullptr;
        auto *temp = last->previous;
        delete last;
        last = temp;
    }else if(index > 0){
        struct item *ptr = first;
        while(index){
            ptr = ptr->next;
            index--;
        }
        ptr->previous->next = ptr->next;
        ptr->next->previous = ptr->previous;
        delete ptr;
    } else {
        struct item *ptr = first;
        while (index){
            ptr = ptr->previous;
            index++;
        }
        ptr->previous->next = ptr->next;
        ptr->next->previous = ptr->previous;
        delete ptr;
    }
    size--;
}

template<class T>
linkedList<T>::linkedList() {
    size = 0;
    first = nullptr;
    last = nullptr;
}

template<class T>
linkedList<T>::linkedList(T *items, size_t amount) {
    first = nullptr;
    last = nullptr;
    size = 0;
    for(int i = 0; i < amount; i++){
        append(items[i]);
    }
}

template<class T>
linkedList<T>::linkedList(const linkedList<T> &list) {
    first = nullptr;
    last = nullptr;
    size = 0;
    struct item *ptr = list.first;
    for(int i = 0; i < list.size; i++){
        append(ptr->value);
        ptr = ptr->next;
    }
}