#include <iostream>

#include "sqeq.h"

int main(int argc, char * argv[]) {
    try {
        std::vector<SqeqParam> prms = validateParameters(argc, argv);
        std::cout << std::endl;
        for (SqeqParam p : prms) {
            p.print();
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "One or more coeffs are non-integer (ERROR: '" << e.what() << "')" << std::endl;
    }


    return 0;
}
