#pragma once

#include <iostream>
#include "eq.h"


// one linear equation:
class LinearEquation :public Equation {
public:
    LinearEquation();
    explicit LinearEquation(const std::vector<int>& coeffs);
    void solve() override;
    [[nodiscard]] std::vector<int> getRoots() const override;
private:
    std::vector<int> m_coeffs;
    std::vector<int> m_roots;
    bool m_isSolved;
};
