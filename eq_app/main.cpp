#include <iostream>
#include "reader.h"
#include "reader_factory.h"
#include "parse.h"
#include "eq_factory.h"
#include "printer.h"

int main(int argc, const char * argv[]) {
    auto reader = createReader(argc, argv);
    int i = 0;
    while (i <= 3) {
        auto currInput = reader->getCoeffs();
        auto coeffs = parseCoeffs(currInput);
        auto eq = createEquation(coeffs);
        eq->solve();
        auto roots = eq->getRoots();
        printEq(coeffs, roots, std::cout);
        std::cout << "\n";
        i++;

    }

    return 0;
}

