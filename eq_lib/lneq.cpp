#include "lneq.h"

LinearEquation::LinearEquation() :
        m_coeffs{}, m_isSolved{false} {
}

LinearEquation::LinearEquation(const std::vector<int>& coeffs) :
        LinearEquation() {
    m_coeffs = coeffs;
}

void LinearEquation::solve() {
    m_roots = {1};
    std::cout << "Linear equation solved: ";
}

std::vector<int> LinearEquation::getRoots() const{
    return m_roots;
}
