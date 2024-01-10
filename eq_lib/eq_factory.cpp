#include "eq_factory.h"

#include "eq.h"
#include "lneq.h"
#include "queq.h"
#include "cbeq.h"
#include "utils.h"


std::unique_ptr<Equation> createEquation(std::vector<int>&& coeffs) {
    std::size_t coeffsAmount = coeffs.size();

    if (coeffsAmount == 2) {
        return std::make_unique<LinearEquation>(coeffs);
    } else if (coeffsAmount == 3) {
        return std::make_unique<QuadraticEquation>(coeffs);
    } else if (coeffsAmount == 4) {
        return std::make_unique<CubicEquation>(coeffs);
    } else {
        std::cout << "Wrong amount of coeffs: " << coeffsAmount << "\n";
        return nullptr;
    }
}


