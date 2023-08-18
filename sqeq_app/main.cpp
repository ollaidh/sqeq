#include <iostream>

#include "sqeq.h"

int main(int argc, char * argv[]) {
    std::vector<SqeqParam> prms = validateParameters(argc, argv);
    for (SqeqParam p : prms) {
        p.print();
    }





//    SqeqParam parameters{1, -2, -3};
//    SquareEquation sqe{};
//    sqe.coeffs = parameters;
//    sqe.solve();
//    sqe.print();

    return 0;
}
