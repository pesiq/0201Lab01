#ifndef LAB02_LINKEDLIST_H
#define LAB02_LINKEDLIST_H

#include <cstdlib>
#include "../exceptions/exceptions.h"
#include <ostream>
template <class T>
class linkedList{
private:
    struct item{
        T value;
        struct item* next;
        struct item* previous;
    };
    int size;
    struct item* first;
    struct item* last;

public:
    //creation
    linkedList(T* items, size_t amount); //create linkedList from static array
    linkedList(); //create empty linkedList
    linkedList(linkedList<T> const &list);  // copy existing linkedList

    //destruction
    ~linkedList();
    void deleteList();

    //decomposition
    T getFirst(); //get first element
    T getLast(); //get last element
    T &get(int index); //get element at index
    linkedList<T>& getSublist(size_t start, size_t end); //create linkedList of elements with index start to the element with index end
    int length(); //get size of linkedList

    //operations
    void deleteItem(int index);
    void set(T val, int index);
    void append(T val); //add to the end
    void prepend(T val); //add to the beginning
    void insertAt(T val, int index); //add at the index
    void concatenate(linkedList<T> list); //concatenate 2 lists

    linkedList<T>& operator=(const linkedList<T>& list){
        deleteList();
        first = list.first;
        last = list.last;
        size= list.size;
        return *this;
    }

    friend std::ostream &operator<< (std::ostream &temp, linkedList<T> &l1){
        struct item *ptr = l1.first;
        for (int i = 0; i < l1.size; i++) {
            temp<<ptr->value;
            if(i != l1.size-1) {
                temp << " ";
            }
            ptr = ptr->next;
        }
        return temp;
    }

};

#endif //LAB02_LINKEDLIST_H
