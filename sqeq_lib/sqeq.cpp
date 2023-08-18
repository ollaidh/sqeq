#include "sqeq.h"
#include <iostream>
#include <cstdlib>


void SquareEquation::solve() {
    double discr = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
    if (discr > 0) {
        solution = true;
        x1 = static_cast<int>((-coeffs.b + std::sqrt(discr)) / (2 * coeffs.a));
        x2 = static_cast<int>((-coeffs.b - std::sqrt(discr)) / (2 * coeffs.a));
    } else if (discr == 0) {
        solution = true;
        x1 = static_cast<int>(-coeffs.b / (2 * coeffs.a));
        x2 = x1;
    } else {
        solution = false;
    }
}

void SquareEquation::print() const {
    if (solution) {
        if (x1 != x2) {
            std::cout << "(" << x1 << ", " << x2 << ")";
        } else {
            std::cout << "(" << x1 << ")";
        }
    } else {
        std::cout << "no roots";
    }
}

void SqeqParam::print() const {
    std::cout << "(" << a << " " << b << " " << c << ")";
}

std::vector<SqeqParam> validateParameters(int argc, char * argv[]) {
    // check if number of input parameters is a multiple of 3
    // TODO: Exceptions
//    if ((argc - 1) % 3 != 0) {
//        raise Exception("Wrong number of input parameters")
//    }

//    for (int i = 1; i < argc; i++) {
//        std::cout << argv[i] << std::endl;
//    }
    // number of equations based on passed arguments:
    int equations_number = static_cast<int>((argc - 1) / 3);

    std::vector<SqeqParam> result;
    result.reserve(equations_number);

    int i = 1;
    while (i < argc) {
        SqeqParam params{
                static_cast<double>(std::strtol(argv[i], nullptr, 10)),
                static_cast<double>(std::strtol(argv[i + 1], nullptr, 10)),
                static_cast<double>(std::strtol(argv[i + 2], nullptr, 10))
        };
        result.push_back(params);
        i += 3;
    }
    return result;
}
