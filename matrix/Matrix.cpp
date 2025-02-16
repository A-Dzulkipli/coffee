#include "./Matrix.h"
#include <stdexcept>
#include <format>

void Matrix::constructor_bound_check(int d_1, int d_2) {
    if (d_1 < 0 && d_2 < 0) {
        throw std::invalid_argument("both dimensions are negative");
    }

    else if (d_1 < 0) {
        throw std::invalid_argument("d_1 is negative");
    }

    else if (d_2 < 0) {
        throw std::invalid_argument("d_2 is negative");
    }

    return;
}

void Matrix::bound_check(int d_1, int d_2) {
    if (d_1 < 0 && d_2 < 0) {
        throw std::invalid_argument("both dimensions are negative");
    }

    else if (d_1 < 0) {
        throw std::invalid_argument("d_1 is negative");
    }

    else if (d_2 < 0) {
        throw std::invalid_argument("d_2 is negative");
    }

    else if (d_1 >= this->d_1 && d_2 >= this->d_2) {
        throw std::invalid_argument(std::format("d_1 is larger than {} and d_2 is larger than {}", this->d_1 - 1, this->d_2 -1));
    }

    else if (d_1 >= this->d_1) {
        throw std::invalid_argument(std::format("d_1 is larger than {}", this->d_1 - 1));
    }

    else if (d_1 >= this->d_1) {
        throw std::invalid_argument(std::format("d_2 is larger than {}", this->d_2 - 1));
    }

    return;
}

Matrix::Matrix(int d_1, int d_2) : d_1(d_1), d_2(d_2) {
    this->constructor_bound_check(d_1, d_2);

    mat = std::vector<std::vector<float>> (d_1, std::vector<float>(d_2, 0));
}

Matrix::Matrix(std::vector<std::vector<float>> mat) {
    d_1 = mat.size();

    if (d_1 == 0) {
        throw std::invalid_argument(std::format("d_1 is size 0"));
    }

    d_2 = mat[0].size();

    if (d_2 == 0) {
        throw std::invalid_argument(std::format("d_1 is size 0"));
    }

    this->mat = mat;
}

float Matrix::get(int d_1, int d_2) {
    this->bound_check(d_1, d_2);
    return this->mat[d_1][d_2];
}

int Matrix::set(int d_1, int d_2, float n) {
    this->bound_check(d_1, d_2);
    this->mat[d_1][d_2] = n;

    return 0;
}