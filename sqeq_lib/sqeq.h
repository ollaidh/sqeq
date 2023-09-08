#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <charconv>

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
};

// quadratic equation roots:
struct QueqRoots {
    double x1;
    double x2;
};

// one quadratic equation:
class QuadraticEquation {
public:
    QuadraticEquation();
    explicit QuadraticEquation(QueqParam coeffs);

    [[nodiscard]] std::optional<double> x1() const;
    [[nodiscard]] std::optional<double> x2() const;
    [[nodiscard]] std::optional<bool> isSolved() const;
    [[nodiscard]] double xExtr() const;
    [[nodiscard]] double yExtr() const;
    void solve();
    void findExtremums();
    void printRoots(std::ostream& stream) const;
    void printExtr(std::ostream& stream) const;
private:
    QueqParam m_coeffs;
    std::optional<QueqRoots> m_roots;
    bool m_isSolved;
    double m_xExtr;
    double m_yExtr;
};

std::vector<int> transformParams(int argc, char * argv[], int pack_length);
int stringviewToInt(std::string_view& strv);
std::variant<QueqParam, ParamParsingErr> parsePackQueq(
        std::string_view a,
        std::string_view b,
        std::string_view c);
