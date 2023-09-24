#include "eq.h"

bool Equation::operator==(const Equation &other) const {
    return m_coeffs == other.m_coeffs;
}