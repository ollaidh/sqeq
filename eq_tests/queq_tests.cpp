#include <gtest/gtest.h>
#include "queq.h"

TEST(queq, solve) {
    QuadraticEquation eq1({1, -2, -3});
    std::vector<double> expected1 = {3, -1};
    eq1.solve();
    std::vector<double> roots1 = eq1.getRoots();
    ASSERT_EQ(roots1, expected1);

    QuadraticEquation eq2({3, -6, 3});
    std::vector<double> expected2 = {1};
    eq2.solve();
    std::vector<double> roots2 = eq2.getRoots();
    ASSERT_EQ(roots2, expected2);

    QuadraticEquation eq3({1, 1, 1});
    std::vector<double> expected3 = {};
    eq3.solve();
    std::vector<double> roots3 = eq3.getRoots();
    ASSERT_EQ(roots3, expected3);
}