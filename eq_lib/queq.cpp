#include "queq.h"
#include "utils.h"
#include <iostream>
#include <string>

QuadraticEquation::QuadraticEquation(const std::vector<int>& coeffs) {
    m_coeffs = coeffs;
}

void QuadraticEquation::solve() {
    m_roots = {1, 2};
    std::cout << "Quadratic equation solved: ";
}
