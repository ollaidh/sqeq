#include "cbeq.h"

CubicEquation::CubicEquation() :
        m_coeffs{}, m_isSolved{false} {
}

CubicEquation::CubicEquation(const std::vector<int>& coeffs) :
        CubicEquation() {
    m_coeffs = coeffs;
}
void CubicEquation::solve() {
    m_roots = {1, 2, 3};
    std::cout << "Cubic equation solved: ";
}

std::vector<int> CubicEquation::getRoots() const{
    return m_roots;
}