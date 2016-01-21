#include <iostream>
#include "Matrix.hpp"

template <class T>
Matrix<T>::Matrix(int i, int j) {
    this->matrix.assign(i, std::vector<T>(j, NULL));
}

template <class T>
Matrix<T>::fill() {
    for (std::vector<T>::iterator it = this->matrix.begin(); it != this->matrix.end(); it++) {
        
    }
}
