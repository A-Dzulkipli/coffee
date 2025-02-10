#include "./Matrix.h"
#include <cmath>
#include <string>
#include <stdexcept>

bool test_get_0() {
    Matrix m = Matrix(1,1);
    return abs(m.get(0,0)) < 1e-9;
}

bool test_get_and_set_0() {
    Matrix m = Matrix(1,1);
    m.set(0,0,2);
    return m.get(0,0) == 2;
}

bool test_constructor_0() {
    try {
        Matrix m = Matrix(-1, 0);
    }

    catch(std::invalid_argument& error) {
        return true;
    }

    return false;
}

bool test_get_1() {
    Matrix m = Matrix(1,1);
    
    try {
        return m.get(0,0) == 0;
    }

    catch(std::invalid_argument& error) {
        return false;
    }
}

bool test_get_2() {
    Matrix m = Matrix(1,1);

    try {
        m.get(1,0);
        return false;
    }

    catch(std::invalid_argument& error) {
        return true;
    }
}