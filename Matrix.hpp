#include <iostream>
#include <vector>

template <typename T>
class Matrix {
private:
    std::vector< std::vector<T> > matrix;
public:
    Matrix(int i, int j) {
        this->matrix.assign(i, std::vector<T>(j, 0));
    }
    void fillWith(T x) {
        for(int i = 0; i < this->matrix.size(); i++) {
            for (int j = 0; j < this->matrix[i].size(); j++) {
                this->matrix[i][j] = x;
            }
        }
    }
    void printMatrix() {
        for(int i = 0; i < this->matrix.size(); i++) {
            std::cout << "|\t";
            for (int j = 0; j < this->matrix[i].size(); j++) {
                std::cout << this->matrix[i][j] << "\t";
            }
            std::cout << "|" << std::endl;
        }
    }
};
