#include "sqeq.h"
#include <iostream>
#include <cstdlib>


void SquareEquationSolution::solve() {
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

void SquareEquationSolution::print() const {
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

// add zeroes to the end of parameters pack, as we assume that missing coeffs at the end equal zeroes:
std::vector<int> transformParams(int argc, char * argv[]) {
    std::vector<int> result;
    for (int i = 1; i < argc; i++) {
        // TODO: wrap in try-catch, in catch throw exception with specified message for non-int input
        result.push_back(std::stoi(argv[i]));
    }

    if ((argc - 1) % 3 != 0) {
        int expected_coeff_number = 3 * ((argc - 1) / 3 + 1);
        int real_coeff_number = argc - 1;
        for (int i = 0; i < (expected_coeff_number - real_coeff_number); i++) {
            result.push_back(0);
        }
    }
    return result;
}

std::vector<SqeqParam> validateParameters(int argc, char * argv[]) {
    std::vector<SqeqParam> result;

    const std::vector<int> coeffs = transformParams(argc, argv);

    int i = 0;
    while (i < argc) {
        SqeqParam params{
                static_cast<double>(coeffs[i]),
                static_cast<double>(coeffs[i + 1]),
                static_cast<double>(coeffs[i + 2])
        };
        result.push_back(params);
        i += 3;
    }
    return result;
}
