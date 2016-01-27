#include <iostream>
#include <string>

class MatrixType {
private:
    int i;
    int j;
public:
    MatrixType(int i, int j);
    bool sameType(MatrixType type);
    std::string asString();
};