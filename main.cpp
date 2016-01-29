#include <iostream>
#include "Matrix.hpp"
#include "SymbolabFormatter.hpp"
#include "WolframAlphaFormatter.hpp"

int main() {
    // Matrix matrix(true);
    // matrix.printMatrix();
    // std::cout << "-----------------------------------------------" << std::endl;
    // matrix.transpose()->printMatrix();
    // std::cout << matrix.symbolabString() << std::endl;
    // std::cout << matrix.symbolabTransposeString() << std::endl;
    // Matrix m1(RANDOMIC);
    Matrix m1(8);
    m1.autoFill(5);
    m1.printMatrix();
    std::cout << "-----------------------------------------------" << std::endl;
    m1.topTriangulationWithGaussianElimination()->printMatrix();
    // m1.getSubMatrix(0, 0)->getSubMatrix(0, 0)->printMatrix();
    // std::cout.precision(15);
    std::cout << "det(m1) = " << double(m1.determinant()) << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    (m1 + &m1)->printMatrix();
    std::cout << WolframAlphaFormatter::matrixDeterminantString(&m1) << std::endl;
    return 0;
}
