#include "cbeq.h"

#include <cmath>

#include "utils.h"


CubicEquation::CubicEquation(std::vector<int> coeffs)
    : Equation{std::move(coeffs)}
{

}

void CubicEquation::solve() {
    // reduce the equation:
    double a = double(m_coeffs[1]) / m_coeffs[0];
    double b = double(m_coeffs[2]) / m_coeffs[0];
    double c = double(m_coeffs[3]) / m_coeffs[0];

    // introduce additional variables to avoid code duplication
    double aQuad = a * a;
    double aDiv3 = a / 3;
    double PiTwoDivThree = (2.0 / 3) * M_PI;

    // Q, R, S variables values define the way to calculate roots
    double Q = (aQuad - 3 * b) / 9;
    double Qcubic = Q * Q * Q;
    double minus2sqrtQ = -2 * sqrt(std::abs(Q));
    double R = (2 * a * aQuad - 9 * a * b + 27 * c) / 54;
    double S = Qcubic - R * R;
    double sR = sign(R);
    double cbrtR = cbrt(R);

    if (S == 0) {
        double x1 = -2 * cbrtR - aDiv3;
        double x2 = cbrtR - aDiv3;
        m_roots = {x1, x2};
    } else if (S > 0) {
        double phi = (1.0 / 3) * acos((std::abs(R) / (sqrt(std::abs(Qcubic)))));
        double x1 = minus2sqrtQ * cos(phi) - aDiv3;
        double x2 = minus2sqrtQ * cos(phi + PiTwoDivThree) - aDiv3;
        double x3 = minus2sqrtQ * cos(phi - PiTwoDivThree) - aDiv3;
        m_roots = {x1, x2, x3};
    } else {
        if (Q > 0) {
            double phi = 1.0 / 3 * acosh(R / sqrt(Qcubic));
            double x1 = minus2sqrtQ * sR * cosh(phi) - aDiv3;
            // x2 and x3 are complex, skip them here
            m_roots = {x1};
        } else if (Q < 0) {
            double phi = 1.0 / 3 * asinh(std::abs(R) / sqrt(std::abs(Qcubic)));
            double x1 = minus2sqrtQ * sR * sinh(phi) - aDiv3;
            // x2 and x3 are complex, skip them here
            m_roots = {x1};
        } else {
            double x1 = -cbrt((c - a * aQuad / 27)) - aDiv3;
            // x2 and x3 are complex, skip them here
            m_roots = {x1};
        };
    }
    m_isSolved = true;
}

