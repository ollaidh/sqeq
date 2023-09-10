#include "sqeq.h"
#include <iostream>
#include <fstream>
#include <sstream>


bool QueqParam::operator==(const QueqParam& other) const {
    return a == other.a && b == other.b && c == other.c;
}

bool ParamParsingErr::operator==(const ParamParsingErr& other) const {
    return coeffs.compare(other.coeffs) && message.compare(other.message);
}

void QueqParam::print(std::ostream& stream) const {
    stream << "(" << a << " " << b << " " << c << ")";
}

// OLD:
std::vector<int> transformParams(int argc, char * argv[], int pack_length) {
    if (argc < 2) {
        throw std::invalid_argument("Wrong input: No coefficients were provided!");
    }
    std::vector<int> result;

    int i = 1;
    while (i < argc) {
        std::vector<int> coeff_pack;
        bool pack_ok = true;
        try {
            for (int j = i; j < std::min((i + pack_length), argc); j++) {
                    coeff_pack.push_back(std::stoi(argv[j]));
            }
        } catch (const std::invalid_argument&) {
            pack_ok = false;
//          throw std::invalid_argument("Wrong input: One or more coefficients are not INT!");
            std::cout << " Invalid parameter, skipping pack! ";
        }
        if (pack_ok) {
            for (int c : coeff_pack) {
                result.push_back(c);
            }
        }
        i += pack_length;
    }

    int real_coeff_number = int(result.size());
    if (real_coeff_number % 3 != 0) {
        int expected_coeff_number = 3 * (real_coeff_number / 3 + 1);
        for (int k = 0; k < (expected_coeff_number - real_coeff_number); k++) {
            result.push_back(0);
        }
    }
    return result;
}

std::vector<std::string> splitString(const std::string& word, const char& separator) {
    std::vector<std::string> result;
    std::string  s;
    std::istringstream ss(word);
    while (getline(ss, s, separator)) {
        if (!s.empty()) {
            result.push_back(s);
        }
    }
    return result;
}

// Read coeffs input sequence from file:
std::vector<std::string> readCoeffsFromFile(std::string &filepath) {
    std::vector<std::string> result;
    std::ifstream file(filepath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> coeffs;
            std::string  s;
            std::istringstream ss(line);

            while (getline(ss, s, ' ')) {
//                std::cout << s << " ";
                if (!s.empty()) {
                    coeffs.push_back(s);
                }
            }
            for (const std::string& c : coeffs) {
                std::cout << "'" << c << "'" << " ";
            }
        }
    }
    return result;
}


// Convert string_view to int:
int stringviewToInt(std::string_view& strv) {
    int result;
    auto conv = std::from_chars(strv.data(), strv.data() + strv.size(), result);
    if (conv.ec == std::errc::invalid_argument || conv.ptr != strv.data() + strv.size()) {
        throw std::invalid_argument("");
    }
    return result;
}

// Parse coeffs for single SQUARE equation:
std::variant<QueqParam, ParamParsingErr> parsePackQueq(
        std::string_view a,
        std::string_view b,
        std::string_view c) {
    try {
        QueqParam params{stringviewToInt(a), stringviewToInt(b), stringviewToInt(c)};
        if (params.a == 0) {
            return ParamParsingErr{
                std::string(a) + " " + std::string(b) + " " + std::string(c),
                "Wrong input: Not a quadratic equation."};
        }
        return params;
    } catch (const std::invalid_argument&)  {
        ParamParsingErr parse_err{
            std::string(a) + " " + std::string(b) + " " + std::string(c),
            "Wrong input: Non-int coefficients."
        };
        return parse_err;
    }
}

QuadraticEquation::QuadraticEquation() :
        m_coeffs{}, m_isSolved{false}, m_xExtr{0}, m_yExtr{0} {
}

QuadraticEquation::QuadraticEquation(QueqParam coeffs) :
        QuadraticEquation() {
    m_coeffs = coeffs;
}

// OLD:
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

// OLD:
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

// OLD:
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













