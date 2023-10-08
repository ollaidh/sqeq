#include <iostream>

#include "eq_factory.h"
#include "reader.h"
#include "reader_factory.h"
#include "parse.h"
#include "printer.h"

int main(int argc, const char * argv[]) {
    try {
        auto reader = createReader(argc, argv);
        while (!reader->atEnd()) {
            auto currInput = reader->getCoeffs();
            auto coeffs = parseCoeffs(currInput);
            if (coeffs.empty()) {
                std::cout << "Bad coeffs pack ";
                print_sequence(currInput, std::cout);
                std::cout <<  "! Skipping this equation.";
                std::cout << "\n";
                continue;
            }
            auto eq = createEquation(coeffs);
            eq->solve();
            auto roots = eq->getRoots();
            printEq(coeffs, roots, std::cout);
            std::cout << "\n";
        }
    } catch (std::invalid_argument& e) {
        std::cout << e.what();
    }

    return 0;
}

