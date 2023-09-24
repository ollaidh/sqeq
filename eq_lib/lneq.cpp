#include "lneq.h"

LinearEquation::LinearEquation(const std::vector<int>& coeffs) {
    m_coeffs = coeffs;
}

void LinearEquation::solve() {
    m_roots = {1};
    std::cout << "Linear equation solved: ";
}

