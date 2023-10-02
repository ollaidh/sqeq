#include <gtest/gtest.h>
#include "printer.h"

TEST(print, basic) {
    {
        std::vector<int> coeffs{1, 2, 3};
        std::vector<double> roots{1.1, 2.1, 3.1};

        std::stringstream stream;
        print_eq(coeffs, roots, stream);
        ASSERT_EQ("(1 2 3) => (1.1 2.1 3.1)", stream.str());
    }

    {
        std::vector<int> coeffs{1, 2, 3};
        std::vector<double> roots{};

        std::stringstream stream;
        print_eq(coeffs, roots, stream);
        ASSERT_EQ("(1 2 3) => no roots", stream.str());
    }




}