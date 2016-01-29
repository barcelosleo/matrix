#include "SymbolabFormatter.hpp"
#include <sstream>

std::string SymbolabFormatter::matrixString(Matrix* matrix) {
    std::string output = "\\begin{pmatrix}";
    for (int i = 0; i < matrix->getI(); i++) {
        //Verifica se é a primeira linha a ser inserida. Se não adiciona \\ para quebrar a linha
        if (i != 0) {
            output += "\\";
        }
        for (int j = 0; j < matrix->getJ(); j++) {
            // Transforma o número em string
            std::ostringstream strs;
            strs << matrix->getAt(i, j);
            output += strs.str();
            // Verifica se não é o último elemento da linha
            if (j != (matrix->getJ() - 1)) {
                output += "&";
            }
        }
        output += "\\";
    }
    output += "end{pmatrix}";
    return output;
}

std::string SymbolabFormatter::transposedMatrixString(Matrix *matrix) {
    return "transpose" + SymbolabFormatter::matrixString(matrix);
}

std::string SymbolabFormatter::matrixSumString(Matrix *m1, Matrix *m2) {
    return SymbolabFormatter::matrixString(m1) + "\\:+\\:" + SymbolabFormatter::matrixString(m2);
}

std::string SymbolabFormatter::matrixProductString(Matrix *m1, Matrix *m2) {
    return SymbolabFormatter::matrixString(m1) + "\\cdot " + SymbolabFormatter::matrixString(m2);
}

std::string SymbolabFormatter::matrixDeterminantString(Matrix* matrix) {
    return "det" + SymbolabFormatter::matrixString(matrix);
}
