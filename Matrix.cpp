#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Matrix.hpp"

Matrix::Matrix() {
    this->initializer = 0;
}

Matrix::Matrix(bool random) {
    this->initializer = 0;
    this->randomMatrix();
}

Matrix::Matrix(int d) {
    this->initializer = 0;
    this->createMatrix(d, d);
    this->setMatrixType(d, d);
}

Matrix::Matrix(int i, int j) {
    this->initializer = 0;
    this->createMatrix(i, j);
    this->setMatrixType(i, j);
}

Matrix::~Matrix() {

}

void Matrix::setMatrixType(int i, int j) {
    this->type.i = i;
    this->type.j = j;
}

void Matrix::createMatrix(int i, int j) {
    this->matrix.assign(i, std::vector<double>(j, this->initializer));
}

void Matrix::setInitializer(double initializer) {
    this->initializer = initializer;
}

double Matrix::getInitializer() {
    return this->initializer;
}

void Matrix::fillWith(double x) {
    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[i].size(); j++) {
            this->matrix[i][j] = x;
        }
    }
}

void Matrix::randomMatrix(int limitI, int limitJ) {
    srand(time(NULL));
    int i = rand() % limitI + 1;
    int j = rand() % limitJ + 1;
    this->matrix.assign(i, std::vector<double>(j, this->initializer));
    this->setMatrixType(i, j);
    this->autoFill();
}

void Matrix::autoFill(int limit) {
    srand(time(NULL));
    for (int i = 0; i < this->getI(); i++) {
        for (int j = 0; j < this->getJ(); j++) {
            this->matrix[i][j] = rand() % limit + 1;
        }
    }
}

void Matrix::printMatrix() {
    for (int i = 0; i < this->getI(); i++) {
        std::cout << "|\t";
        for (int j = 0; j < this->getJ(); j++) {
            std::cout << this->matrix[i][j] << "\t";
        }
        std::cout << "|" << std::endl;
    }
}

void Matrix::swap(double* p1, double* p2) {
    double tmp = (*p1);
    (*p1) = (*p2);
    (*p2) = tmp;
}

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

Matrix* Matrix::opposite() {
    Matrix* opposite = new Matrix(this->getI(), this->getJ());
    for (int i = 0; i < this->getI(); i++) {
        for (int j = 0; j < this->getJ(); j++) {
            opposite->insertAt(i, j, this->matrix[i][j] * -1);
        }
    }
    return opposite;
}

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

Matrix* Matrix::sum(Matrix* matrix) {
    if (this->sameType(this, matrix)) {
        Matrix* sum = new Matrix(this->getI(), this->getJ());
        for (int i = 0; i < this->getI(); i++) {
            for (int j = 0; j < this->getJ(); j++) {
                sum->insertAt(i, j, (this->matrix[i][j] + matrix->getAt(i, j)));
            }
        }
        return sum;
    }
    throw "Matriz não somavel!";// Aprender exceptions em C++
}

Matrix* Matrix::multiply(Matrix *matrix) {
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
    throw "Matriz não multiplicavel!";
}

Matrix* Matrix::multiply(double number) {
    Matrix* product = new Matrix(this->getI(), this->getJ());
    for (int i = 0; i < this->getI(); i++) {
        for (int j = 0; j < this->getJ(); j++) {
            product->insertAt(i, j, this->matrix[i][j] * number);
        }
    }
    return product;
}

Matrix* Matrix::subtract(Matrix *matrix) {
    if (this->sameType(this, matrix)) {
        Matrix* sum = new Matrix(this->getI(), this->getJ());
        for (int i = 0; i < this->getI(); i++) {
            for (int j = 0; j < this->getJ(); j++) {
                sum->insertAt(i, j, (this->matrix[i][j] - matrix->getAt(i, j)));
            }
        }
        return sum;
    }
    throw "Matriz não subtrativa!";// Aprender exceptions em C++
}

bool Matrix::sameType(Matrix* m1, Matrix* m2) {
    return (m1->getI() == m2->getI() && m1->getJ() == m2->getJ());
}

bool Matrix::multipliable(Matrix* m1, Matrix* m2) {
    return (m1->getI() == m2->getJ() && m1->getJ() == m2->getI());
}

void Matrix::insertAt(int i, int j, double value) {
    this->matrix[i][j] = value;
}

void Matrix::sumAt(int i, int j, double value) {
    this->matrix[i][j] += value;
}

double Matrix::getAt(int i, int j) {
    return this->matrix[i][j];
}

int Matrix::getI() {
    return this->type.i;
}

int Matrix::getJ() {
    return this->type.j;
}

Matrix* Matrix::operator* (Matrix* matrix) {
    return this->multiply(matrix);
}

Matrix* Matrix::operator* (double number) {
    return this->multiply(number);
}

Matrix* Matrix::operator+ (Matrix* matrix) {
    return this->sum(matrix);
}

Matrix* Matrix::operator-(Matrix* matrix) {
    return this->subtract(matrix);
}
