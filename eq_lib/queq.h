#pragma once

#include <iostream>

#include "eq.h"

// Realization of Equation interface for quadratic equation:
class QuadraticEquation :public Equation {
public:
    explicit QuadraticEquation(std::vector<int> coeffs);
    void solve() override;
};
