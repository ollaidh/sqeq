#pragma once
#include <iostream>

class Equation {
public:
    Equation() = default;
    virtual ~Equation() = default;
    virtual void solve() = 0;
    [[nodiscard]] virtual std::vector<int> getRoots() const = 0;
};

std::unique_ptr<Equation> createEquation(const std::vector<int>& coeffs);

