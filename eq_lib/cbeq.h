#include <iostream>
#include <eq.h>
//#include "eq_params.h"


// one Cubic equation:
class CubicEquation :public Equation{
public:
    CubicEquation();
    explicit CubicEquation(std::vector<int> coeffs);

    void solve();
    std::vector<int> getRoots();
private:
    std::vector<int> m_coeffs;
    std::vector<int> m_roots;
    bool m_isSolved;
};
