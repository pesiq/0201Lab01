//
// Created by pesel on 26.05.2021.
//

#ifndef LAB02_EXCEPTIONS_H
#define LAB02_EXCEPTIONS_H

#include <exception>
#include <cstdlib>
#include <string>

class indexOutOfRange : public std::exception {
public:
const char * what() const noexcept override{
    return "Invalid index!";
}

};

class invalidArgument : public std::exception {
public:
const char * what() const noexcept override{
    return "Bad argument!";
}
};

#endif //LAB02_EXCEPTIONS_H
