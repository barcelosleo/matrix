#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include <iostream>
#include <string>
#include "Matrix.hpp"

class Formatter {
public:
    /**
     * Retorna string da representação de uma matriz para software de 3ºs
     */
    static std::string matrixString(Matrix* matrix);
    /**
     * Retorna string da representação de uma matriz transposta para software de 3ºs
     */
    static std::string transposedMatrixString(Matrix* matrix);
    /**
     * Retorna string da representação de uma soma de matrizes para software de 3ºs
     */
    static std::string matrixSumString(Matrix* m1, Matrix* m2);
    /**
     * Retorna string da representação de uma soma de matrizes para software de 3ºs
     */
    static std::string matrixSubtractionString(Matrix* m1, Matrix* m2);
    /**
     * Retorna string da representação de um produto de matrizes para software de 3ºs
     */
    static std::string matrixProductString(Matrix* m1, Matrix* m2);
    /**
     * Retorna string da representação da determinante de uma matriz para software de 3ºs
     */
    static std::string matrixDeterminantString(Matrix* matrix);
    /**
     * Retorna string da representação da matriz inversa para software de 3ºs
     */
};

#endif
