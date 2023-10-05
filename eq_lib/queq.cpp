#include "queq.h"

#include <string>

#include "utils.h"

QuadraticEquation::QuadraticEquation(const std::vector<int>& coeffs) {
    m_coeffs = coeffs;
}

void QuadraticEquation::solve() {
    double a = m_coeffs[0];
    double b = m_coeffs[1];
    double c = m_coeffs[2];

    // to get rid of code repetitions:
    double discr = b * b - 4 * a * c;
    double atwice = 2 * a;
    double lp = -b / atwice;
    double rp = std::sqrt(discr) / atwice;

    if (discr > 0) {
        double x1 = lp + rp;
        double x2 = lp - rp;
        m_roots = {x1, x2};
    } else if (discr == 0) {
        double x1 = -b / atwice;
        m_roots = {x1};
    }
    m_isSolved = true;
}

