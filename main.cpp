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
    // Matrix m1(267);
    // Matrix m1({{2, 1}, {4, 3}});
    Matrix m1({
        {1, 5, 0},
        {4, 3, 4},
        {6, 0, 2}
    });
    // Matrix m1({{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}});
    // Matrix m1({{1, 2, 3}, {0, 1, 4}, {5, 6, 0}});
    // Matrix m1(4);
    // m1.autoFill(15);
    m1.printMatrix();
    std::cout << "-----------------------------------------------" << std::endl;
    // m1.cofactorMatrix()->printMatrix();
    std::cout << "-----------------------------------------------" << std::endl;
    m1.cofactorMatrix()->printMatrix();
    // m1.topTriangulationWithGaussianElimination()->printMatrix();
    // m1.getSubMatrix(0, 0)->getSubMatrix(0, 0)->printMatrix();
    // std::cout.precision(100);
    // m1.opposite()->printMatrix();
    // std::cout << "det(m1) = " << double(m1.determinant()) << std::endl;
    // (m1 + m2)->printMatrix();
    std::cout << "-----------------------------------------------" << std::endl;
    m1.adjointMatrix()->printMatrix();
    // (m1 * (*m1.inverse()))->printMatrix();
    std::cout << "-----------------------------------------------" << std::endl;
    // (m1 + &m1)->printMatrix();
    // m1.inverse()->printMatrix();
    std::cout << WolframAlphaFormatter::matrixString(&m1) << std::endl;
    std::cout << SymbolabFormatter::matrixString(&m1) << std::endl;
    return 0;
}
