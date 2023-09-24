#include "eq.h"

bool Equation::operator==(const Equation &other) const {
    return m_coeffs == other.m_coeffs;
}

std::vector<int> Equation::getRoots() const {
    return m_roots;
}
