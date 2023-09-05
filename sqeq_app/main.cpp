#include <iostream>

#include "sqeq.h"

int main(int argc, char * argv[]) {
    try {
        std::vector<QueqParam> prms = collectParameters(argc, argv);
        for (QueqParam p : prms) {
            QuadraticEquation equation(p);
            equation.solve();
            equation.findExtremums();
            p.print(std::cout);
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
