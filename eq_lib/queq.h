#pragma once

#include <iostream>
#include "eq_params.h"
#include "eq.h"


class QuadraticEquation :public Equation {
public:
    QuadraticEquation();
    explicit QuadraticEquation(const std::vector<int>& coeffs);
    void solve() override;
    [[nodiscard]] std::vector<int> getRoots() const override;
private:
    std::vector<int> m_coeffs;
    std::vector<int> m_roots;
    bool m_isSolved;
};
