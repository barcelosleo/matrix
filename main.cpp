#include <iostream>
#include "Matrix.hpp"

int main() {
    Matrix<float> matrix(3, 3);
    matrix.fillWith(0.0f);
    matrix.printMatrix();
    return 0;
}
