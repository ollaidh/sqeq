#pragma once
#include "eq.h"
#include "lneq.h"
#include "queq.h"
#include "cbeq.h"

std::unique_ptr<Equation> createEquation(std::vector<std::string> input) {
    int coeffsAmount = input.size();

    if (coeffsAmount == 2) {
        std::vector<int> coeffs = {1, 2};
        return std::make_unique<LinearEquation>(coeffs);
    } else if (coeffsAmount == 3) {
        std::vector<int> coeffs = {1, 2, 3};
        return std::make_unique<QuadraticEquation>(coeffs);
    } else if (coeffsAmount == 4) {
        std::vector<int> coeffs = {1, 2, 3, 4};
        return std::make_unique<CubicEquation>(coeffs);
    } else {
        // TODO change into Raise Error:
        std::cout << "Bad amount of coeffs: " << coeffsAmount << "\n";
        return nullptr;
    }
}
