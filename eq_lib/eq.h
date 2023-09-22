#pragma once

#include <iostream>

class Equation {
public:
    Equation() = default;
    virtual ~Equation() = default;
    virtual void solve() = 0;
};

std::unique_ptr<Equation> createEquation(std::vector<std::string> coeffs);

