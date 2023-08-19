#include <iostream>

#include "sqeq.h"

int main(int argc, char * argv[]) {

    std::vector<SqeqParam> prms = validateParameters(argc, argv);
    std::cout << std::endl;
    for (SqeqParam p : prms) {
        p.print();
    }

    return 0;
}
