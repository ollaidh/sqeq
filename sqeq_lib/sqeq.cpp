#include "sqeq.h"
#include <iostream>

bool SqeqParam::operator==(const SqeqParam& other) const {
    return a == other.a && b == other.b && c == other.c;
}

void SqeqParam::print() const {
    std::cout << "(" << a << " " << b << " " << c << ")";
}

// Transform initial coefficients from command line arguments to int vector.
// Also adding zeroes to the end of parameters pack, as we assume that missing coeffs at the end equal zeroes:
std::vector<int> transformParams(int argc, char * argv[]) {
    if (argc < 2) {
        throw std::invalid_argument("Wrong input: No coefficients were provided!");
    }
    std::vector<int> result;
    for (int i = 1; i < argc; i++) {
        try {
            result.push_back(std::stoi(argv[i]));
        } catch (const std::invalid_argument&) {
            throw std::invalid_argument("Wrong input: One or more coefficients are not INT!");
        }
    }

    if ((argc - 1) % 3 != 0) {
        int expected_coeff_number = 3 * ((argc - 1) / 3 + 1);
        int real_coeff_number = argc - 1;
        for (int i = 0; i < (expected_coeff_number - real_coeff_number); i++) {
            result.push_back(0);
        }
    }
    return result;
}

// Organizing equations coeffs into SqeqParam structure for each equation:
std::vector<SqeqParam> collectParameters(int argc, char * argv[]) {
    std::vector<SqeqParam> result;

    const std::vector<int> coeffs = transformParams(argc, argv);

    int i = 0;
    while (i < argc - 1) {
        SqeqParam params{
                static_cast<double>(coeffs[i]),
                static_cast<double>(coeffs[i + 1]),
                static_cast<double>(coeffs[i + 2])
        };
        result.push_back(params);
        i += 3;
    }
    return result;
}

QuadraticEquationSolution::QuadraticEquationSolution() :
        m_coeffs{}, m_x1{0}, m_x2{0}, m_hasSolution{false}, m_solved{false}, m_xExtr{0}, m_yExtr{0} {
}

QuadraticEquationSolution::QuadraticEquationSolution(SqeqParam coeffs) :
        QuadraticEquationSolution() {
    m_coeffs = coeffs;
}

// Solve quadratic equation:
void QuadraticEquationSolution::solve() {
    if (m_coeffs.a == 0 && m_coeffs.b == 0 && m_coeffs.b == 0) {
        m_x1 = INFINITY;
        m_x2 = INFINITY;
        m_hasSolution = true;
    } else if (m_coeffs.b == 0 && m_coeffs.b == 0) {
        m_x1 = 0;
        m_x2 = m_x1;
        m_hasSolution = true;
    } else if (m_coeffs.a == 0) {
        m_x1 = -m_coeffs.c / m_coeffs.b;
        m_x2 = m_x1;
        m_hasSolution = true;
    } else {
        double discr = m_coeffs.b * m_coeffs.b - 4 * m_coeffs.a * m_coeffs.c;
        if (discr > 0) {
            m_x1 = (-m_coeffs.b + std::sqrt(discr)) / (2 * m_coeffs.a);
            m_x2 = (-m_coeffs.b - std::sqrt(discr)) / (2 * m_coeffs.a);
            m_hasSolution = true;
        } else if (discr == 0) {
            m_x1 = -m_coeffs.b / (2 * m_coeffs.a);
            m_x2 = m_x1;
            m_hasSolution = true;
        } else {
            m_hasSolution = false;
        }
    }
    m_solved = true;
}

double QuadraticEquationSolution::x1() const {
    return m_x1;
}

double QuadraticEquationSolution::x2() const {
    return m_x2;
}

bool QuadraticEquationSolution::hasSolution() const {
    return m_hasSolution;
}

bool QuadraticEquationSolution::isSolved() const {
    return m_solved;
}

double QuadraticEquationSolution::xExtr() const {
    return m_xExtr;
}

double QuadraticEquationSolution::yExtr() const {
    return m_yExtr;
}

// Calculate extremums of quadratic function
void QuadraticEquationSolution::findExtremums() {
    if (m_coeffs.a != 0) {
        m_xExtr = -m_coeffs.b / (2 * m_coeffs.a);
        if (m_xExtr == -0) {m_xExtr = 0;}
        // according to examples in task description, we don't need to print Y-coord of extremum, so just calculating it:
        m_yExtr = m_coeffs.a * m_xExtr * m_xExtr + m_coeffs.b * m_xExtr + m_coeffs.c;
        if (m_yExtr == -0) {m_yExtr = 0;}
    }
}

// Print roots of equation
void QuadraticEquationSolution::printRoots(std::ostream& stream) const {
    if (m_hasSolution) {
        if (m_x1 != m_x2) {
            stream << "(" << m_x1 << ", " << m_x2 << ")";
        } else if (m_x1 == std::numeric_limits<double>::infinity() || m_x1 == -std::numeric_limits<double>::infinity()) {
            stream << "Infinite number of roots";
        }
        else {
            stream << "(" << m_x1 << ")";
        }
    } else {
        stream << "no roots";
    }
}

// Print extremums
void QuadraticEquationSolution::printExtr(std::ostream& stream) const {
    if (m_coeffs.a != 0) {
        stream << "Xmin=" << m_xExtr;
    } else {
        stream << "No extremum";
    }

}













