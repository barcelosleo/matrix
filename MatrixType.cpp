#include <iostream>
#include "MatrixType.hpp"

MatrixType::MatrixType(int i, int j) {
    this->i = i;
    this->j = j;
}

bool MatrixType::sameType(MatrixType type) {
    return (this->i == type.i && this->j == type.j);
}

std::string MatrixType::asString() {
    return std::string();
}