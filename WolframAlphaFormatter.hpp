#ifndef WOLFRAM_ALPHA_FORMATTER_HPP
#define WOLFRAM_ALPHA_FORMATTER_HPP

#include <iostream>
#include "Formatter.hpp"

class WolframAlphaFormatter: public Formatter{
public:
    WolframAlphaFormatter();
    /**
     * Retorna uma string que pode ser usada no symbolab para testes
     */
    static std::string matrixString(Matrix* matrix);
    /**
     * Retorna string para symbolab para transposição da matriz
     */
    static std::string transposedMatrixString(Matrix* matrix);
    /**
     * Retorna string para symbolab da soma de duas matrizes
     */
    static std::string matrixSumString(Matrix* m1, Matrix* m2);
    /**
     * Retorna string para symbolab do produto de duas matrizes
     */
    static std::string matrixProductString(Matrix* m1, Matrix* m2);
    /**
     * Retorna string para symbolab da determinante de uma matriz
     */
    static std::string matrixDeterminantString(Matrix* matrix);
};

#endif
