#include <iostream>
#include "utils.h"
#include "eq.h"

//#include "solve.h"
//#include "inheritance_test.h"
//#include "visitor_sandbox.h"

int main(int argc, char * argv[]) {
    std::vector<std::string> coeffs{"1", "2", "3"};
    std::unique_ptr<Equation> eq = createEquation(coeffs);
    eq->solve();




//    Equation linearEq = LinearEquation{};
//    Equation quadraticEq = QuadraticEquation{};
//    Equation cubicEq = CubicEquation{};
//
//    solve(linearEq);
//    solve(quadraticEq);
//    solve(cubicEq);



//    std::string filepath = "/Users/maria/Documents/CPP/SquareEquation/coeffs_input.txt";
//    solveFromFile(filepath);
//    splitString("a b c d", ' ');
//    solveEq(3);


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

