#pragma once
#include <iostream>
#include <cmath>


// one set of quadratic equation parameters:
struct SqeqParam {
    double a;
    double b;
    double c;

    bool operator==(const SqeqParam& other) const;
    void print() const;
};

// one quadratic equation:
class QuadraticEquationSolution {
public:
    QuadraticEquationSolution();
    explicit QuadraticEquationSolution(SqeqParam coeffs);

    [[nodiscard]] double x1() const;
    [[nodiscard]] double x2() const;
    [[nodiscard]] bool hasSolution() const;
    [[nodiscard]] bool isSolved() const;
    [[nodiscard]] double xExtr() const;
    [[nodiscard]] double yExtr() const;
    void solve();
    void findExtremums();
    void printRoots(std::ostream& stream) const;
    void printExtr(std::ostream& stream) const;
private:
    SqeqParam m_coeffs;
    double m_x1;
    double m_x2;
    bool m_hasSolution;
    bool m_solved;
    double m_xExtr;
    double m_yExtr;
};

std::vector<int> transformParams(int argc, char * argv[]);
std::vector<SqeqParam> collectParameters(int argc, char * argv[]);
