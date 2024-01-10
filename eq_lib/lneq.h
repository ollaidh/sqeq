#pragma once

#include <iostream>

#include "eq.h"

// Realization of Equation interface for linear equation:
class LinearEquation :public Equation {
public:
    explicit LinearEquation(std::vector<int> coeffs);
    void solve() override;
};
