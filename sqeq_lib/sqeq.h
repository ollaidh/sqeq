#pragma once
#include <iostream>
#include <cmath>


// one set of square equation parameters:
struct SqeqParam {
    double a;
    double b;
    double c;

    void print() const;
};

// one square equation:
class SquareEquation {
public:
    SqeqParam coeffs;
    int x1;
    int x2;
    bool solution;

    void solve();
    void print() const;
};

std::vector<int> transformParams(int argc, char * argv[]);
std::vector<SqeqParam> validateParameters(int argc, char * argv[]);
