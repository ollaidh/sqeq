#pragma once

#include <iostream>

struct LneqParam {
    int a;
};

// one set of quadratic equation parameters:
struct QueqParam : LneqParam {
    int b;
    int c;

    bool operator==(const QueqParam& other) const;
    void print(std::ostream& stream) const;
};

struct CbeqParam {
    int d;
};

// errors of parsing:
struct ParamParsingErr {
    std::string coeffs;  // all coefficients from pack where invalid coeffs occur
    std::string message;  // error message

    bool operator==(const ParamParsingErr& other) const;
};