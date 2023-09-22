#include <iostream>
#include <inheritance_test.h>

//void Eq :: solve() {
//    std::cout << "Solved equation." << std::endl;
//};

void LinEq :: solve() {
    std::cout << "Solved Linear equation." << std::endl;
};

void QuadEq :: solve() {
    std::cout << "Solved Quadratic equation." << std::endl;
};

void CubEq :: solve() {
    std::cout << "Solved Cubic equation." << std::endl;
};

void solving(Eq &equation) {

}
