#pragma once

#include <iostream>
#include "eq.h"
//#include "eq_params.h"


// one linear equation:
class LinearEquation :public Equation {
public:
    LinearEquation();
    explicit LinearEquation(std::vector<int> coeffs);
    void solve();
    std::vector<int> getRoots();
private:
    std::vector<int> m_coeffs;
    std::vector<int> m_roots;
    bool m_isSolved;
};
