#include "printer.h"

void printEq(const std::vector<int>& coeffs, const std::vector<double>& roots, std::ostream &stream) {
    print_sequence(coeffs, stream);
    stream << " => ";
    if (roots.empty()) {
        stream << "no roots";
    } else {
        print_sequence(roots, stream);
    }
}
