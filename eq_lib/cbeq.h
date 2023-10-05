#include <iostream>
#include <eq.h>

class CubicEquation :public Equation{
public:
    explicit CubicEquation(const std::vector<int>& coeffs);
    void solve() override;
};
