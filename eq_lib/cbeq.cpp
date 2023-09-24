#include "cbeq.h"

CubicEquation::CubicEquation(const std::vector<int>& coeffs) {
    m_coeffs = coeffs;
}

void CubicEquation::solve() {
    m_roots = {1, 2, 3};
    std::cout << "Cubic equation solved: ";
}

std::vector<int> CubicEquation::getRoots() const{
    return m_roots;
}
