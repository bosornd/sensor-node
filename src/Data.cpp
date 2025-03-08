#include <iostream>

#include "Data.hpp"

Data::Data(int data) : data(data) {}

Data::Data(const Data& other) : data(other.data) {}

Data& Data::operator=(int data) {
    std::cout << "Data processed" << std::endl;
    this->data = data;
    return *this;
}

Data& Data::operator=(const Data& other) {
    std::cout << "Data copied" << std::endl;
    data = other.data;
    return *this;
}

Data::operator int() const {
    return data;
}