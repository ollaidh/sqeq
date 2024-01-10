#include "lneq.h"

LinearEquation::LinearEquation(std::vector<int> coeffs)
    : Equation{std::move(coeffs)}
{

}

void LinearEquation::solve() {
    double a = m_coeffs[0];
    double b = m_coeffs[1];
    double x = - b / a;
    m_roots = {x};
    m_isSolved = true;
}

