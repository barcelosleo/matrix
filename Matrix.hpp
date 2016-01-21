#include <iostream>
#include <vector>

template <class T>
class Matrix {
private:
    std::vector<std::vector<T>> matrix;
public:
    Matrix(int i, int j);
    void fill();
};
