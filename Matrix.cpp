#include <sstream>
#include <exception>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "Matrix.hpp"
#include "Exceptions/MatrixException.hpp"

/**
 * {inherited}
 */
Matrix::Matrix() {
    this->initializer = 0;
    this->gaussEliminationSwaps = 0;
}

/**
 * {inherited}
 */
Matrix::Matrix(matrix_double matrix) {
    this->initializer = 0;
    this->gaussEliminationSwaps = 0;
    this->matrix = matrix;
    this->setMatrixType(matrix.size(), matrix[0].size());
}

/**
 * {inherited}
 */
Matrix::Matrix(bool random) {
    this->initializer = 0;
    this->gaussEliminationSwaps = 0;
    this->randomMatrix();
}

/**
 * {inherited}
 */
Matrix::Matrix(int d) {
    this->initializer = 0;
    this->gaussEliminationSwaps = 0;
    this->createMatrix(d, d);
    this->setMatrixType(d, d);
}

/**
 * {inherited}
 */
Matrix::Matrix(int i, int j) {
    this->initializer = 0;
    this->gaussEliminationSwaps = 0;
    this->createMatrix(i, j);
    this->setMatrixType(i, j);
}

/**
 * {inherited}
 */
Matrix::~Matrix() {

}

/**
 * {inherited}
 */
void Matrix::setMatrixType(int i, int j) {
    this->type.i = i;
    this->type.j = j;
}

/**
 * {inherited}
 */
void Matrix::createMatrix(int i, int j) {
    this->matrix.assign(i, std::vector<double>(j, this->initializer));
}

/**
 * {inherited}
 */
void Matrix::setInitializer(double initializer) {
    this->initializer = initializer;
}

/**
 * {inherited}
 */
double Matrix::getInitializer() {
    return this->initializer;
}

/**
 * {inherited}
 */
void Matrix::fillWith(double x) {
    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[i].size(); j++) {
            this->matrix[i][j] = x;
        }
    }
}

/**
 * {inherited}
 */
void Matrix::randomMatrix(int limitI, int limitJ) {
    srand(time(NULL));
    int i = rand() % limitI + 1;
    int j = rand() % limitJ + 1;
    this->matrix.assign(i, std::vector<double>(j, this->initializer));
    this->setMatrixType(i, j);
    this->autoFill();
}

/**
 * {inherited}
 */
void Matrix::autoFill(int limit) {
    int min = -limit;
    int max = limit;
    srand(time(NULL));
    for (int i = 0; i < this->getI(); i++) {
        for (int j = 0; j < this->getJ(); j++) {
            this->matrix[i][j] = round((float(rand()) / float(RAND_MAX)) * (max - min) + min);
        }
    }
}

/**
 * {inherited}
 */
void Matrix::printMatrix() {
    for (int i = 0; i < this->getI(); i++) {
        std::cout << "|\t";
        for (int j = 0; j < this->getJ(); j++) {
            std::cout << this->matrix[i][j] << "\t";
        }
        std::cout << "|" << std::endl;
    }
}

/**
 * {inherited}
 */
void Matrix::swap(double* p1, double* p2) {
    double tmp = (*p1);
    (*p1) = (*p2);
    (*p2) = tmp;
}

void Matrix::swapRows(int i1, int i2) {
    std::vector<double> tmp = this->matrix[i1];
    this->matrix[i1] = this->matrix[i2];
    this->matrix[i2] = tmp;
}

/**
 * {inherited}
 */
Matrix* Matrix::transpose() {
    // Instacia uma matriz J x I, pois o resultado da transposição de uma matriz I x J origina uma matriz J xI
    Matrix* transposed = new Matrix(this->getJ(), this->getI());
    for (int i = 0; i < this->getI(); i++) {
        for (int j = 0; j < this->getJ(); j++) {
            // Verifica se a matriz tem mais de uma linha e coluna, para evitar 'segmentation fault'
            if (this->getI() <= 1 && this->getJ() <= 1) {
                transposed->insertAt(i, j, this->matrix[i][j]);
            } else {
                transposed->insertAt(j, i, this->matrix[i][j]);
            }
        }
    }
    return transposed;
}

/**
 * {inherited}
 */
Matrix* Matrix::opposite() {
    Matrix* opposite = this->copy();
    return ((*opposite) * -1.0);
}

/**
 * {inherited}
 */
Matrix* Matrix::identity() {
    Matrix* identity = new Matrix(this->getI(), this->getJ());
    for (int i = 0; i < this->getI(); i++) {
        for (int j = 0; j < this->getJ(); j++) {
            if (i == j) {
                identity->insertAt(i, j, 1);
            }
        }
    }
    return identity;
}

/**
 * {inherited}
 */
Matrix* Matrix::sum(Matrix* matrix) {
    try {
        if (this->sameType(this, matrix)) {
            Matrix* sum = new Matrix(this->getI(), this->getJ());
            for (int i = 0; i < this->getI(); i++) {
                for (int j = 0; j < this->getJ(); j++) {
                    sum->insertAt(i, j, (this->matrix[i][j] + matrix->getAt(i, j)));
                }
            }
            return sum;
        }
        throw MatrixException("Matriz não somável");// Aprender exceptions em C++
    } catch (MatrixException e) {
        std::cout << e.what() << std::endl;
    }
}

/**
 * {inherited}
 */
Matrix* Matrix::multiply(Matrix *matrix) {
    try {
        if (this->multipliable(this, matrix)) {
            // O produto de uma matriz I1xJ1 por I2xJ2 resulta uma matriz J1xI2
            Matrix* product = new Matrix(this->getJ(), matrix->getI());
            for (int i = 0; i < this->getI(); i++) {
                for (int j = 0; j < matrix->getJ(); j++) {
                    for (int k = 0; k < this->getI(); k++) {
                        product->sumAt(i, j, (this->matrix[i][k] * matrix->getAt(k, j)));
                    }
                }
            }
            return product;
        }
        throw MatrixException("Matriz não multiplicável");
    } catch (MatrixException e) {
        std::cout << e.what() << std::endl;
    }
}

/**
 * {inherited}
 */
Matrix* Matrix::multiply(double number) {
    Matrix* product = new Matrix(this->getI(), this->getJ());
    for (int i = 0; i < this->getI(); i++) {
        for (int j = 0; j < this->getJ(); j++) {
            // std::cout << this->matrix[i][j] << " * " << number << std::endl;
            product->insertAt(i, j, this->matrix[i][j] * number);
        }
    }
    return product;
}

/**
 * {inherited}
 */
Matrix* Matrix::subtract(Matrix *matrix) {
    try {
        if (this->sameType(this, matrix)) {
            Matrix* sum = new Matrix(this->getI(), this->getJ());
            for (int i = 0; i < this->getI(); i++) {
                for (int j = 0; j < this->getJ(); j++) {
                    sum->insertAt(i, j, (this->matrix[i][j] - matrix->getAt(i, j)));
                }
            }
            return sum;
        }
        throw MatrixException("Matriz não subtrativa");// Aprender exceptions em C++
    } catch (MatrixException e) {
        std::cout << e.what() << std::endl;
    }
}

/**
 * {inherited}
 */
Matrix* Matrix::getSubMatrix(int I, int J) {
    Matrix* subMatrix = new Matrix(this->getI() - 1, this->getJ() - 1);
    for (int i = 0, iSub = 0; i < this->getI(); i++) {
        for (int j = 0, jSub = 0; j < this->getJ(); j++) {
            if (i != I && j != J) {
                subMatrix->insertAt(iSub, jSub, this->matrix[i][j]);
                jSub++;
            }
        }
        if (i != I) iSub++;
    }
    return subMatrix;
}

/**
 * {inherited}
 */
double Matrix::determinant() {
    try {
        if (this->isSquare()) {
            return this->determinant(this->topTriangulationWithGaussianElimination()) *  pow(-1, this->gaussEliminationSwaps);
        }
        throw MatrixException("Matriz não é quadrada");
    } catch (MatrixException e) {
        std::cout << e.what() << std::endl;
    }
}

/**
 * {inherited}
 */
double Matrix::determinant(Matrix *matrix) {
    return this->mainDiagonaProduct(matrix);
}

/**
* {inherited}
*/
double Matrix::recursiveDeterminant(Matrix *matrix) {
    // matrix->printMatrix();
    if (matrix->getI() < 1) {
        throw "Dimensão da matriz é menor que 1!";
    } else if(matrix->getI() == 1) {
        return matrix->matrix[0][0];
    } else if(matrix->getI() == 2) {
        return (
            (matrix->matrix[0][0] * matrix->matrix[1][1]) - (matrix->matrix[0][1] * matrix->matrix[1][0])
        );
    } else {
        double det = 0;
        for (int i = 0; i < matrix->getI(); i++) {
            Matrix* subMatrix = matrix->getSubMatrix(0, i);
            det += pow(-1, i) * matrix->matrix[0][i] * this->determinant(subMatrix);
        }
        return det;
    }
}

/**
* {inherited}
*/
double Matrix::mainDiagonaProduct(Matrix *matrix) {
    double product = 1;
    for (int i = 0; i < matrix->getI(); i++) {
        for (int j = 0; j < matrix->getJ(); j++) {
            j != i ?: product *= matrix->getAt(i, j);
        }
    }
    return product;
}

int Matrix::gaussElimination(Matrix* matrix) {
    int n = matrix->getI();
    this->gaussEliminationSwaps = 0;

    for (int k = 0; k < n; ++k) {
        int imax = this->findMax(matrix, k);
        if (matrix->getAt(imax, k) == 0) return 0;
        matrix->swapRows(k, imax);
        // Verifica se foi feito o swap entre duas linhas diferentes.
        // Ao calcular a determinante o número de swaps será o expoente de -1, assim ditando se o
        // resultado da determinante será multiplicado por 1 ou -1
        if (k != imax) {
            // std::cout << "Fez swap de L" << k << " com L" << imax << std::endl;
            // std::cout << "Swaps = " << this->gaussEliminationSwaps << std::endl;
            this->gaussEliminationSwaps++;
        }
        for (int i = k + 1; i < n; ++i) {
            double c = matrix->getAt(i, k) / matrix->getAt(k, k);
            matrix->insertAt(i, k, 0);
            for (int j = k + 1; j < n; ++j) {
                matrix->subtractAt(i, j, (c * matrix->getAt(k, j)));
            }
        }
    }
    return this->gaussEliminationSwaps;
}

Matrix* Matrix::topTriangulationWithGaussianElimination() {
    Matrix* topTriangulation = this->copy();
    this->gaussElimination(topTriangulation);
    return topTriangulation;
}

Matrix* Matrix::cofactorMatrix() {
    Matrix* cofactorMatrix = new Matrix(this->getI(), this->getJ());
    for (int i = 0; i < this->getI(); i++) {
        for (int j = 0; j < this->getJ(); j++) {
            cofactorMatrix->insertAt(i, j, (pow(-1, (i + j)) * this->determinant(this->getSubMatrix(i, j))));
        }
    }
    return cofactorMatrix;
}

Matrix* Matrix::adjointMatrix() {
    return this->cofactorMatrix()->transpose();
}

Matrix* Matrix::inverse() {
    try {
        double determinant = this->determinant();
        if (determinant != 0) {
            return ((*this->adjointMatrix()) * double(1 / determinant));
            return this->adjointMatrix()->multiply(1 / determinant);
        }
        throw MatrixException("Matriz não inversível");
    } catch (MatrixException e) {
        std::cout << e.what() << std::endl;
    }
}

/**
 * {inherited}
 */
bool Matrix::sameType(Matrix* m1, Matrix* m2) {
    return (m1->getI() == m2->getI() && m1->getJ() == m2->getJ());
}

/**
 * {inherited}
 */
bool Matrix::multipliable(Matrix* m1, Matrix* m2) {
    return (m1->getI() == m2->getJ() && m1->getJ() == m2->getI());
}

/**
 * {inherited}
 */
bool Matrix::isSquare() {
    return this->getI() == this->getJ();
}

/**
 * {inherited}
 */
void Matrix::insertAt(int i, int j, double value) {
    this->matrix[i][j] = value;
}

/**
 * {inherited}
 */
void Matrix::sumAt(int i, int j, double value) {
    this->matrix[i][j] += value;
}

/**
 * {inherited}
 */
void Matrix::subtractAt(int i, int j, double value) {
    this->matrix[i][j] -= value;
}

/**
* {inherited}
*/
int Matrix::findMax(Matrix* matrix, int index) {
    int n = this->getI();

    double imax = index;
    double maxPivot = abs(matrix->getAt(index, index));

    for (int i = index + 1; i < n; ++i) {
        double a = abs(matrix->getAt(i, index));
        if (a > maxPivot) {
            maxPivot = a;
            imax = i;
        }
    }
    return imax;
}

/**
 * {inherited}
 */
Matrix* Matrix::copy() {
    Matrix* copy = new Matrix(this->getI(), this->getJ());
    for (int i = 0; i < this->getI(); i++) {
        for (int j = 0; j < this->getJ(); j++) {
            copy->insertAt(i, j, this->matrix[i][j]);
        }
    }
    return copy;
}

/**
 * {inherited}
 */
double Matrix::getAt(int i, int j) {
    return this->matrix[i][j];
}

/**
 * {inherited}
 */
int Matrix::getI() {
    return this->type.i;
}

/**
 * {inherited}
 */
int Matrix::getJ() {
    return this->type.j;
}

/**
 * {inherited}
 */
Matrix* Matrix::operator* (Matrix matrix) {
    return this->multiply(&matrix);
}

/**
 * {inherited}
 */
Matrix* Matrix::operator* (double number) {
    return this->multiply(number);
}

/**
 * {inherited}
 */
Matrix* Matrix::operator+ (Matrix matrix) {
    return this->sum(&matrix);
}

/**
 * {inherited}
 */
Matrix* Matrix::operator-(Matrix matrix) {
    return this->subtract(&matrix);
}

/**
 * {inherited}
 */
void Matrix::operator<< (matrix_double matrix) {
    this->matrix = matrix;
}
