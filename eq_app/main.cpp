#include <iostream>
#include "sqeq.h"
#include "utils.h"

int main(int argc, char * argv[]) {
    std::string filepath = "/Users/maria/Documents/CPP/SquareEquation/coeffs_input.txt";
    solveFromFile(filepath);
    std::cout << "Ping!";
    splitString("a b c d", ' ');


//    std::string_view a = "0";
//    std::string_view b = "1";
//    std::string_view c = "2";
//    std::variant<QueqParam, ParamParsingErr> coeffs = parsePackQueq(a, b, c);
//    auto k = std::get<ParamParsingErr>(coeffs);
//    std::cout << k.message << " " << k.coeffs;
//    auto k = std::get<QueqParam>(coeffs);
//    k.print(std::cout);

//    try {
//        std::vector<std::variant<QueqParam, ParamParsingErr>> prms = parseParameters(argc, argv, 3);
//
//        for (QueqParam p : prms) {
//            QuadraticEquation equation(p);
//            equation.solve();
//            equation.findExtremums();
//            p.print(std::cout);
//            std::cout << " => ";
//            equation.printRoots(std::cout);
//            std::cout << " ";
//            equation.printExtr(std::cout);
//            std::cout << std::endl;
//        }
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error occurred: '" << e.what() << "'" << std::endl;
//    }

    return 0;
}

