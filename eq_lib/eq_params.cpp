#include "eq_params.h"

bool QueqParam::operator==(const QueqParam& other) const {
    return a == other.a && b == other.b && c == other.c;
}

bool ParamParsingErr::operator==(const ParamParsingErr& other) const {
    return coeffs.compare(other.coeffs) && message.compare(other.message);
}

void QueqParam::print(std::ostream& stream) const {
    stream << "(" << a << " " << b << " " << c << ")";
}
