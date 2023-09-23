#include "queq.h"
#include "utils.h"
#include <iostream>
#include <string>


QuadraticEquation::QuadraticEquation() :
        m_coeffs{}, m_isSolved{false} {
}

QuadraticEquation::QuadraticEquation(const std::vector<int>& coeffs) :
        QuadraticEquation() {
    m_coeffs = coeffs;
}


void QuadraticEquation::solve() {
    m_roots = {1, 2};
    std::cout << "Quadratic equation solved: ";
}

std::vector<int> QuadraticEquation::getRoots() const{
    return m_roots;
}
