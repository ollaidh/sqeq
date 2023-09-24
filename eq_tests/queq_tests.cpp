#include <gtest/gtest.h>
#include "queq.h"

TEST(queq, solve) {
    QuadraticEquation eq({1, -2, -3});
    std::vector<int> expected = {-1, 3};
    eq.solve();
    std::vector<int> roots = eq.getRoots();
    ASSERT_EQ(roots, expected);
}