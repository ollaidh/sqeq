#include <iostream>
#include <eq.h>
//#include "eq_params.h"


// one Cubic equation:
class CubicEquation :public Equation{
public:
    explicit CubicEquation(const std::vector<int>& coeffs);
    void solve() override;
    [[nodiscard]] std::vector<int> getRoots() const override;
};
