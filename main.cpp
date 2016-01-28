#include <iostream>
#include "Matrix.hpp"
#include "SymbolabFormatter.hpp"

int main() {
    // Matrix matrix(true);
    // matrix.printMatrix();
    // std::cout << "-----------------------------------------------" << std::endl;
    // matrix.transpose()->printMatrix();
    // std::cout << matrix.symbolabString() << std::endl;
    // std::cout << matrix.symbolabTransposeString() << std::endl;
    Matrix m1(2);
    m1.autoFill();
    m1.printMatrix();
    std::cout << "-----------------------------------------------" << std::endl;
    (m1 * 2.0)->printMatrix();
    std::cout << "-----------------------------------------------" << std::endl;
    (m1 * &m1)->printMatrix();
    std::cout << SymbolabFormatter::matrixProductString(&m1, &m1) << std::endl;
    return 0;
}
