#pragma once

#include <iostream>
#include "eq.h"


// one linear equation:
class LinearEquation :public Equation {
public:
    explicit LinearEquation(const std::vector<int>& coeffs);
    void solve() override;
};
