//
// Created by pesel on 28.05.2021.
//

#ifndef LAB02_LISTSEQUENCE_H
#define LAB02_LISTSEQUENCE_H

#include "sequence.h"
#include "../lower/linkedList.h"
#include "../lower/linkedList.cpp"

template<class T>
class listSequence : public sequence<T>{
private:
    linkedList<T> list;
public:

    listSequence(){
        list = linkedList<T>();
    }

    listSequence(T* arr, int amount){
        list = listSequence(arr, amount);
    }

    listSequence(linkedList<T> const &arr){
        list = linkedList<T>(arr);
    }

    ~listSequence(){
        list.deleteList();
    }

    void deleteSequence(){
        list.deleteList();
    }


    int length(){
       return list.length();
    }

    void append(T val){
        list.append(val);
    }

    void prepend(T val){
        list.prepend(val);
    }

    void insertAt(T val, int index){
        list.insertAt(val, index);
    }

    T get(int index){
        return list.get(index);
    }

    T getFirst(){
        return list.getFirst();
    }

    T getLast(){
        return list.getLast();
    }

    void deleteItem(int index){
        list.deleteItem(index);
    }

    void set(T val, int index){

    }

    listSequence<T>& getSubsequence(int start, int end){
        listSequence<T> newlist = list.getSublist(start, end);
        listSequence<T> *newseq = new listSequence<T>();
        for(int i = 0; i < newseq->length(); i++){
            newseq->append(newlist.get(i));
        }
        return *newseq;
    }

    void concatenate(sequence<T> *li){
        for(int i = 0; i<li->length(); i++){
            this->append(li->get(i));
        }
    }

    T &operator[](int i){
        return list.get(i);
    }

    listSequence<T> &operator= (listSequence<T> &list1){
        list = list1.list;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &temp, listSequence<T>& s1){
        temp << s1.list;
        return temp;
    }

};

#endif //LAB02_LISTSEQUENCE_H
