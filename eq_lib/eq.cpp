#include <cassert>

#include "eq.h"

Equation::Equation(std::vector<int> coeffs) : m_coeffs{std::move(coeffs)} {

}

bool Equation::operator==(const Equation &other) const {
    return m_coeffs == other.m_coeffs;
}

std::vector<double> Equation::getRoots() const {
    // this function can't be called if an equation wasn't solved
    assert(m_isSolved);
    return m_roots;
}

std::vector<int> Equation::getCoeffs() const {
    return m_coeffs;
}
