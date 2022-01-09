#ifndef LAB02_SET_H
#define LAB02_SET_H

#include "../sequence/listSequence.h"

template<class T>
class Set{
private:
    listSequence<T> set;
public:
    Set() = default;

    explicit Set(listSequence<T>& s1){
        for(int i = 0; i < s1.length(); i++){
            this->add(s1[i]);
        }
    }

    int size(){
        return set.length();
    }

    void add(T value){

        if(set.length() == 0){
            set.prepend(value);
            return;
        }

        int i;
        for(i = 0; i < set.length(); i++){
            if(set[i] > value){
                set.insertAt(value, i);
                return;
            }
            if(set[i] == value){
                return;
            }
        }
        set.append(value);
    }

    void remove(T value){
        for (int i = 0; i < set.length(); i++){
            if(value == set[i]){
                set.deleteItem(i);
            }
        }

    }

    Set<T>& intersection(Set<T>& s1){
        auto *result = new Set<T>;
        int index1 = 0;
        int index2 = 0;
        while(index1 < size() && index2 < s1.size()){
            T element1 = set[index1];
            T element2 = s1.set[index2];

            if(set[index1] == s1.set[index2]){
                result->add(set[index2]);
                index1++;
                index2++;
            }
            else if (element1 > element2){
                index2++;
            } else {
                index1++;
            }
        }
        return *result;
    }

    Set<T>& difference(Set<T>& s1){
        auto *result = new Set<T>(s1.set);
        int index1 = 0;
        int index2 = 0;
        while(index1 < size() && index2 < s1.size()){
            T element1 = set[index1];
            T element2 = s1.set[index2];

            if(set[index1] == s1.set[index2]){
                result->remove(set[index2]);
                index1++;
                index2++;
            }
            else if (element1 > element2){
                index2++;
            } else {
                index1++;
            }
        }
        return *result;
    }

    void unionize(Set<T>& s2){
        Set<T> tmp = difference(s2);

        for(int i = 0; i < tmp.size(); i++){
            this->add(tmp.set[i]);
        }
    }

    bool includeSubset(Set<T>& s1){
        Set<T> temp = this->intersection(s1);
        return s1.equal(temp);
    }

    bool includeElement(T value){
        for(int i = 0; i < size(); i++){
            if(set[i] == value){
                return true;
            }
        }
        return false;
    }

    bool equal(Set<T>& s1){
        if(s1.size() != set.length()){
            return false;
        }
        for(int i = 0; i < set.length(); i++){
            if(set[i] != s1.set[i]){
                return false;
            }
        }
        return true;
    }

    friend std::ostream &operator<<(std::ostream &temp, Set<T>& s1){
        temp <<'[' << s1.set << ']';
        return temp;
    }

    Set<T> &operator=(Set<T> s1){
        set = s1.set.getSubsequence(0, s1.set.length()-1);
        return *this;
    }
};

#endif
