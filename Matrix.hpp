#include <iostream>
#include <vector>

typedef std::vector< std::vector<double> > matrix_double;

class Matrix {
private:
    matrix_double matrix;
    matrix_double cache;
public:
    /**
     * Construtor vazio
     */
    Matrix();
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
     * Prenche a matrix com o valor de x
     */
    void fillWith(double x);
    /**
     * Gera uma matriz randômica de I x J dimensões. Por padrão o limite de Linhas(I) e Colunas(J) é 10
     */
    void autoFill(int limitI = 10, int limitJ = 10);
    /**
     * Mostra a matriz na tela
     */
    void printMatrix();
    /**
     * Retorna a matriz transposta
     */
    Matrix transpose();
    /**
     * Retorna a matriz identidade
     */
    Matrix identity();
    /**
     * Retorna a soma da matriz com outra matriz
     */
    Matrix sum(Matrix matrix);
    /**
     * Retorna a subtração da matriz com outra
     */
    Matrix subtract(Matrix matrix);
    /**
     * Retorna a multiplicação da matriz com outra
     */
    Matrix multiply(Matrix matrix);
    /**
     * Retorna a multiplicação da matriz por um número
     */
    Matrix multiply(double number);
    /**
     * Retorna a determinante da matriz
     */
    double determinant();
    /**
     * Retorna a determinante de uma submatriz
     */
    double determinant(Matrix subMatrix);
    /**
     * Retorna a matriz de cofatores da matriz
     */
    Matrix cofactorMatrix();
    /**
     * Retorna a matriz adjunta
     */
    Matrix adjointMatrix();
};
