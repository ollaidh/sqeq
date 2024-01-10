#include "eq_factory.h"

#include "eq.h"
#include "lneq.h"
#include "queq.h"
#include "cbeq.h"
#include "utils.h"


std::unique_ptr<Equation> createEquation(std::vector<int> coeffs) {
    std::size_t coeffsAmount = coeffs.size();

    if (coeffsAmount == 2) {
        return std::make_unique<LinearEquation>(std::move(coeffs));
    }
    if (coeffsAmount == 3) {
        return std::make_unique<QuadraticEquation>(std::move(coeffs));
    }
    if (coeffsAmount == 4) {
        return std::make_unique<CubicEquation>(std::move(coeffs));
    }
    std::cout << "Wrong amount of coeffs: " << coeffsAmount << "\n";
    return nullptr;
}


