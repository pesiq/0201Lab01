#ifndef LAB02_VECTOR_H
#define LAB02_VECTOR_H

#include "../sequence/arraySequence.h"

template<class T>
class Vector{
private:
    arraySequence<T> coordinates;
public:

    Vector() = default;

    Vector(T* coords, int dim){
        coordinates = arraySequence<T>(coords, dim);
    }

    explicit Vector(int size){
        coordinates = arraySequence<T>(size);
    }

    explicit Vector(arraySequence<T> &vec){
        coordinates = vec;
    }

    int dim(){
        return coordinates.length();
    }

    void changeDimensions(int amount){
        coordinates.resize(amount);
    }

    T& operator[](int i){
        return coordinates[i];
    }

    Vector<T>& operator=(const Vector<T> v1){
        coordinates = v1.coordinates;
        return *this;
    }

    Vector<T>& addVectors(Vector<T>& vec1){

        if(vec1.dim() != dim()){
            throw invalidArgument();
        }

        int size = dim();
        auto *res = new Vector<T>(size);

        for (int i = 0; i < size; i++) {
            res->coordinates[i] = coordinates[i] + vec1[i];
        }
        return *res;
    }

    Vector<T>& subVectors(Vector<T>& vec1){

        if(vec1.dim() != dim()){
            throw invalidArgument();
        }

        int size = dim();
        auto *res = new Vector<T>(size);

        for (int i = 0; i < size; i++) {
            res->coordinates[i] = coordinates[i] - vec1[i];
        }
        return *res;
    }

    Vector<T>& operator+(const Vector<T>& v1){
        return this->addVectors(v1);
    }

    Vector<T>& operator-(const Vector<T>& v1){
        return this->subVectors(v1);
    }

    T operator*(Vector<T>& v1){

        T accumulator;
        if(v1.dim() != this->dim()){
            throw invalidArgument();
        }

        for (int i = 0; i < v1.dim(); i++) {
            accumulator = (*this)[i] * v1[i];
        }
        return accumulator;
    }

    Vector<T>& operator*(const int val){
        auto *res = new Vector<T>;
        for (int i = 0; i < this->dim(); i++) {
            res->coordinates.append((*this)[i] * val);
        }
        return *res;
    }


    friend std::ostream &operator<<(std::ostream& temp, Vector<T>& vec){
        temp << '{';
        for (int i = 0; i < vec.dim(); i++) {
            temp << vec[i];
            if(i == vec.dim()-1){
                temp << '}';
                break;
            }
            temp << ", ";
        }
        return temp;
    }
};

#endif //LAB02_VECTOR_H
