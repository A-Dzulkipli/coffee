#ifndef matrix_h
#define matrix_h

#include <vector>

class Matrix {
private:
    int d_1;
    int d_2;
    std::vector<std::vector<float>> mat;
    void bound_check(int d_1, int d_2);

public:

    Matrix(int d_1, int d_2);
    float get(int d_1, int d_2);
    int set(int d_1, int d_2, float n);

};


#endif