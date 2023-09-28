#pragma once
#include <iostream>

// Base class for all equations
class Equation {
public:
    virtual ~Equation() = default;
    virtual void solve() = 0;
    [[nodiscard]] virtual std::vector<double> getRoots() const;
    bool operator==(const Equation& other) const;
protected:
    std::vector<int> m_coeffs;
    std::vector<double> m_roots;
    bool m_isSolved{};
};

std::unique_ptr<Equation> createEquation(const std::vector<int>& coeffs);

