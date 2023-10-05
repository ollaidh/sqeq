#include <iostream>

#include "eq.h"

template<typename T>
void print_sequence(std::vector<T> sequence, std::ostream& stream) {
    stream << "(";
    int size_seq = int(sequence.size());
    for (int i = 0; i < size_seq; i ++) {
        stream << sequence[i];
        if (i < size_seq - 1) {
            stream << " ";
        }
    }
    stream << ")";
}

void printEq(const std::vector<int>& coeffs, const std::vector<double>& roots, std::ostream& stream);
