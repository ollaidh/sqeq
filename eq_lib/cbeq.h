#include <iostream>
#include <eq.h>

// Realization of Equation interface for cubic equation:
class CubicEquation :public Equation{
public:
    explicit CubicEquation(const std::vector<int>& coeffs);
    void solve() override;
};
