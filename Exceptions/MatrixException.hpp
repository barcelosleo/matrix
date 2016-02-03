#include <iostream>
#include <exception>
#include <string>

class MatrixException: public std::exception {
private:
    std::string mWhat;
public:
    MatrixException(const std::string& _type): mWhat("MatrixError::" + _type) {};
    ~MatrixException() throw() {};
    virtual const char* what() const throw() {
        return mWhat.c_str();
    }
};
