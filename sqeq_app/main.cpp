#include <iostream>

#include "sqeq.h"

int main(int argc, char * argv[]) {
    try {
        std::vector<SqeqParam> prms = collectParameters(argc, argv);
        for (SqeqParam p : prms) {
            QuadraticEquationSolution equation(p);
            equation.solve();
            equation.findExtremums();
            p.print();
            std::cout << " => ";
            equation.printRoots(std::cout);
            std::cout << " ";
            equation.printExtr(std::cout);
            std::cout << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error occurred: '" << e.what() << "'" << std::endl;
    }

    return 0;
}
