#ifndef SYMBOLABFORMATTER_HPP
#define SYMBOLABFORMATTER_HPP

#include <iostream>
#include "Formatter.hpp"

class SymbolabFormatter: public Formatter{
public:
    SymbolabFormatter();
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
};

#endif
