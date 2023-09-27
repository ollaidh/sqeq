#include <cmath>
#include "cbeq.h"
#include "utils.h"

CubicEquation::CubicEquation(const std::vector<int>& coeffs) {
    m_coeffs = coeffs;
}

void CubicEquation::solve() {
    // reduce the equation:
    double a = double(m_coeffs[1]) / m_coeffs[0];
    double b = double(m_coeffs[2]) / m_coeffs[0];
    double c = double(m_coeffs[3]) / m_coeffs[0];

    double Q = (a * a - 3 * b) / 9;
    double R = (2 * a * a - 9 * a * b + 27 * c) / 54;
    double S = Q * Q * Q - R * R;

    if (S == 0) {
        double x1 = -2 * cbrt(R) - a / 3;
        double x2 = cbrt(R) - a / 3;
        m_roots = {x1, x2};
    } else if (S > 0) {
        double phi = (1.0 / 3) * acos((abs(R) / (sqrt(abs(Q * Q * Q)))));
        double x1 = -2 * sqrt(Q) * cos(phi) - a / 3;
        double x2 = -2 * sqrt(Q) * cos(phi + (2.0 / 3) * M_PI) - a / 3;
        double x3 = -2 * sqrt(Q) * cos(phi - (2.0 / 3) * M_PI) - a / 3;
        m_roots = {x1, x2, x3};
    } else {
        if (Q > 0) {
            double phi = 1.0 / 3 * acosh(R / sqrt(Q * Q * Q));
            double x1 = -2 * sign(R) * sqrt(Q) * cosh(phi) - a / 3;
            // x2 and x3 are complex, skip them here
            m_roots = {x1};
        } else if (Q < 0) {
            double phi = 1.0 / 3 * asinh(R / sqrt(Q * Q * Q));
            double x1 = -2 * sign(R) * sqrt(abs(Q)) * sinh(phi) - a / 3;
            // x2 and x3 are complex, skip them here
            m_roots = {x1};
        } else {
            double x1 = -cbrt((c - a * a * a / 27)) - a / 3;
            // x2 and x3 are complex, skip them here
            m_roots = {x1};
        };
    }
}

