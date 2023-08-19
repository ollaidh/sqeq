#include <iostream>

#include "sqeq.h"

int main(int argc, char * argv[]) {
    try {
        std::vector<SqeqParam> prms = validateParameters(argc, argv);
        std::cout << std::endl;
        for (SqeqParam p : prms) {
            auto solved = SquareEquationSolution();
            p.print();
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error occurred: '" << e.what() << "'" << std::endl;
    }


    return 0;
}
