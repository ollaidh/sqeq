#include <iostream>
#include "eq_params.h"

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
    void solve_eq();
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
void solveFromFile(std::string &filepath);
std::variant<QueqParam, ParamParsingErr> parsePackQueq(
        std::string_view a,
        std::string_view b,
        std::string_view c);
