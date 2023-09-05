#include "sqeq.h"
#include <iostream>

bool QueqParam::operator==(const QueqParam& other) const {
    return a == other.a && b == other.b && c == other.c;
}

void QueqParam::print(std::ostream& stream) const {
    stream << "(" << a << " " << b << " " << c << ")";
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
std::vector<QueqParam> collectParameters(int argc, char * argv[]) {
    std::vector<QueqParam> result;

    const std::vector<int> coeffs = transformParams(argc, argv);

    int i = 0;
    while (i < argc - 1) {
        QueqParam params{
                (coeffs[i]),
                (coeffs[i + 1]),
                (coeffs[i + 2])
        };
        result.push_back(params);
        i += 3;
    }
    return result;
}

QuadraticEquation::QuadraticEquation() :
        m_coeffs{}, m_isSolved{false}, m_xExtr{0}, m_yExtr{0} {
}

QuadraticEquation::QuadraticEquation(QueqParam coeffs) :
        QuadraticEquation() {
    m_coeffs = coeffs;
}

// Solve quadratic equation:
// TODO: add solving linear equation when a=0
// For now accept that a coefficient can not be zero
void QuadraticEquation::solve() {
    if (m_coeffs.b == 0 && m_coeffs.c == 0) {
        m_roots->x1 = 0;
        m_roots->x2 = m_roots->x1;
        m_isSolved = true;
    } else {
        double discr = m_coeffs.b * m_coeffs.b - 4 * m_coeffs.a * m_coeffs.c;
        if (discr > 0) {
            m_roots->x1 = (-m_coeffs.b + std::sqrt(discr)) / (2 * m_coeffs.a);
            m_roots->x2 = (-m_coeffs.b - std::sqrt(discr)) / (2 * m_coeffs.a);
            m_isSolved = true;
        } else if (discr == 0) {
            m_roots->x1 = -m_coeffs.b / (2 * m_coeffs.a);
            m_roots->x2 = m_roots->x1;
            m_isSolved = true;
        } else {
            m_isSolved = false;
        }
    }
//    m_solved = true;
}

std::optional<double> QuadraticEquation::x1() const {
    return m_roots->x1;
}

std::optional<double> QuadraticEquation::x2() const {
    return m_roots->x2;
}

std::optional<bool> QuadraticEquation::isSolved() const {
    return m_isSolved;
}

double QuadraticEquation::xExtr() const {
    return m_xExtr;
}

double QuadraticEquation::yExtr() const {
    return m_yExtr;
}

// Calculate extremums of quadratic function
void QuadraticEquation::findExtremums() {
    if (m_coeffs.a != 0) {
        m_xExtr = -m_coeffs.b / (2 * m_coeffs.a);
        if (m_xExtr == -0) {m_xExtr = 0;}
        // according to examples in task description, we don't need to print Y-coord of extremum, so just calculating it:
        m_yExtr = m_coeffs.a * m_xExtr * m_xExtr + m_coeffs.b * m_xExtr + m_coeffs.c;
        if (m_yExtr == -0) {m_yExtr = 0;}
    }
}

// Print roots of equation
void QuadraticEquation::printRoots(std::ostream& stream) const {
    // if equation was solved:
//    if (m_hasSolution.has_value()) {
//        // TODO: сделать ASSERT - поверку чтобы отслеживать что уравнение решалось на этапе компиляции
//        // if equation has solution:
//        if (m_hasSolution.value()) {
//            // if both roots exist:
//            if (m_x1.has_value() && m_x2.has_value()) {
//                // if existing roots are different:
//                if (m_x1 != m_x2) {
//                    stream << "(" << m_x1.value_or(0) << ", " << m_x2.value_or(0) << ")";
//                // if existing roots are equal:
//                } else {
//                    stream << "(" << m_x1.value_or(0) << ")";
//                }
//                // if a=0, b=0, c=0 it is infinite number of roots:
//            } else {
//                stream << "Infinite number of roots";
//            }
//
//        } else {
//            stream << "no roots";
//        }
//    } else {
//        stream << "Not solved";
//    }

}

// Print extremums
void QuadraticEquation::printExtr(std::ostream& stream) const {
    if (m_coeffs.a != 0) {
        stream << "Xmin=" << m_xExtr;
    } else {
        stream << "No extremum";
    }

}













