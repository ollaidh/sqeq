#pragma once

#include <iostream>
#include <vector>

// Base class for all equations
class Equation {
public:
    explicit Equation(std::vector<int> coeffs);
    virtual ~Equation() = default;
    virtual void solve() = 0;
    [[nodiscard]] virtual const std::vector<int>& getCoeffs() const;
    [[nodiscard]] virtual const std::vector<double>& getRoots() const;
    bool operator==(const Equation& other) const;  // overloaded to use in tests
protected:  // use protected to be able to reach fields by child classes LinearEquation, SquareEquation, CubicEquation
    std::vector<int> m_coeffs;
    std::vector<double> m_roots;  // even equations with int coeffs may have double roots
    bool m_isSolved{};  // true when solve() method was called
};


