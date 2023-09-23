#include <iostream>
#include <eq.h>
//#include "eq_params.h"


// one Cubic equation:
class CubicEquation :public Equation{
public:
    CubicEquation();
    explicit CubicEquation(const std::vector<int>& coeffs);

    void solve() override;
    [[nodiscard]] std::vector<int> getRoots() const;
private:
    std::vector<int> m_coeffs;
    std::vector<int> m_roots;
    bool m_isSolved;
};
