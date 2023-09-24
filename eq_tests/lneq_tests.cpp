#include <gtest/gtest.h>
#include "lneq.h"

TEST(lneq, solve) {
    LinearEquation eq1({2, -4});
    std::vector<double> expected1 = {2};
    eq1.solve();
    std::vector<double> roots1 = eq1.getRoots();
    ASSERT_EQ(roots1, expected1);
}