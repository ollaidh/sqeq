#include "eq.h"

bool Equation::operator==(const Equation &other) const {
    return m_coeffs == other.m_coeffs;
}

std::vector<double> Equation::getRoots() const {
    assert(m_isSolved);
    return m_roots;
}
