#include <iostream>
#include <vector>
#include <string>

#ifndef MATRIX_HPP
#define MATRIX_HPP

typedef std::vector< std::vector<double> > matrix_double;

typedef struct Type_ {
    int i;
    int j;
}MatrixType;

class Matrix {
private:
    MatrixType type;
    matrix_double matrix;
    double initializer;
    /**
     * Retorna a soma da matriz com outra matriz
     */
    Matrix* sum(Matrix* matrix);
    /**
     * Retorna a multiplicação da matriz com outra
     */
    Matrix* multiply(Matrix* matrix);
    /**
     * Retorna a multiplicação da matriz por um número
     */
    Matrix* multiply(double number);
    /**
     * Retorna a subtração da matriz com outra
     */
    Matrix* subtract(Matrix* matrix);
public:
    /**
     * Construtor vazio
     */
    Matrix();
    /**
     * Construtor que gera uma matriz randômica
     */
    Matrix(bool random);
    /**
     * Construtor de matriz quadrada
     */
    Matrix(int d);
    /**
     * Inicializa uma matriz I x J
     */
    Matrix(int i, int j);
    /**
     * Destrutor da classe
     */
    ~Matrix();
    /**
     * Método que seta o tipo de matriz
     */
    void setMatrixType(int i, int j);
    /**
     * Cria uma matriz
     */
    void createMatrix(int i, int j);
    /**
     * Seta o valor para inicialização da matriz
     */
    void setInitializer(double initializer);
    /**
     * Pega o valor para inicialização da matriz
     */
    double getInitializer();
    /**
     * Prenche a matrix com o valor de x
     */
    void fillWith(double x);
    /**
     * Gera uma matriz randômica de I x J dimensões. Por padrão o limite de Linhas(I) e Colunas(J) é 10
     */
    void randomMatrix(int limitI = 10, int limitJ = 10);
    /**
     * Preenche a matriz com valores randômicos
     */
    void autoFill(int limit = 100);
    /**
     * Mostra a matriz na tela
     */
    void printMatrix();
    /**
     * Faz um swap entre duas posições da matriz
     */
    void swap(double* p1, double* p2);
    /**
     * Retorna a matriz transposta
     */
    Matrix* transpose();
    /**
     * Retorna a matriz oposta
     */
    Matrix* opposite();
    /**
     * Retorna a matriz identidade
     */
    Matrix* identity();
    /**
     * Retorna a determinante da matriz
     */
    double determinant();
    /**
     * Retorna a determinante de uma submatriz
     */
    double determinant(Matrix* subMatrix);
    /**
     * Retorna a matriz de cofatores da matriz
     */
    Matrix* cofactorMatrix();
    /**
     * Retorna a matriz adjunta
     */
    Matrix* adjointMatrix();
    /**
     * Verifica se duas matrizes são do mesmo tipo
     */
    bool sameType(Matrix* m1, Matrix* m2);
    /**
     * Verifica se uma matriz é multiplicável
     */
    bool multipliable(Matrix* m1, Matrix* m2);
    /**
     * Insere dado na posição [i][j]
     */
    void insertAt(int i, int j, double value);
    /**
     * Soma dado na posição [i][j]
     */
    void sumAt(int i, int j, double value);
    /**
     * Pega dado nas posições [i][j]
     */
     double getAt(int i, int j);
    /**
     * Mostra o número de linhas da matriz
     */
    int getI();
    /**
     * Mostra o número de colunas da matriz
     */
    int getJ();
    /**
    * Modificador de operador + para soma de matrizes
    */
   Matrix* operator+ (Matrix* matrix);
    /**
     * Modificador de operador * para multiplicação de matrizes
     */
    Matrix* operator* (Matrix* matrix);
    /**
     * Modificador de operador * para multiplicação por número
     */
    Matrix* operator* (double number);
    /**
     * Modificador de operador - para subtração de matrizes
     */
    Matrix* operator- (Matrix* matrix);
};

#endif
