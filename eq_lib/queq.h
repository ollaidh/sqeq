#pragma once

#include <iostream>
#include "eq.h"


class QuadraticEquation :public Equation {
public:
    explicit QuadraticEquation(const std::vector<int>& coeffs);
    void solve() override;
};
