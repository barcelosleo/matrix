#include "WolframAlphaFormatter.hpp"
#include <sstream>

std::string WolframAlphaFormatter::matrixString(Matrix* matrix) {
    std::string output = "[";
    for (int i = 0; i < matrix->getI(); i++) {
        output += "[";
        for (int j = 0; j < matrix->getJ(); j++) {
            // Transforma o número em string
            std::ostringstream strs;
            strs << matrix->getAt(i, j);
            output += strs.str();
            // Verifica se não é o último elemento da linha
            if (j != (matrix->getJ() - 1)) {
                output += ",";
            }
        }
        output += "]";
        if (i != matrix->getI() - 1) {
            output += ",";
        }
    }
    output += "]";
    return output;
}

std::string WolframAlphaFormatter::transposedMatrixString(Matrix *matrix) {
    return "transpose" + WolframAlphaFormatter::matrixString(matrix);
}

std::string WolframAlphaFormatter::matrixSumString(Matrix *m1, Matrix *m2) {
    return WolframAlphaFormatter::matrixString(m1) + "+" + WolframAlphaFormatter::matrixString(m2);
}

std::string WolframAlphaFormatter::matrixSubtractionString(Matrix* m1, Matrix* m2) {
    return WolframAlphaFormatter::matrixString(m1) + "-" + WolframAlphaFormatter::matrixString(m2);
}

std::string WolframAlphaFormatter::matrixProductString(Matrix *m1, Matrix *m2) {
    return WolframAlphaFormatter::matrixString(m1) + "*" + WolframAlphaFormatter::matrixString(m2);
}

std::string WolframAlphaFormatter::matrixDeterminantString(Matrix* matrix) {
    return "det" + WolframAlphaFormatter::matrixString(matrix);
}
