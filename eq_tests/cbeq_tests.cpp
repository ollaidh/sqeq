#include <gtest/gtest.h>
#include "cbeq.h"

TEST(cbeq, solve) {
    {
        CubicEquation eq({2, -12, 22, -12});
        std::vector<double> expected = {1, 2, 3};
        eq.solve();
        std::vector<double> roots = eq.getRoots();
        ASSERT_EQ(roots, expected);
    }

    {
        CubicEquation eq({1, 2, 3, 0});
        std::vector<double> expected = {0};
        eq.solve();
        std::vector<double> roots = eq.getRoots();
        ASSERT_EQ(roots, expected);
    }

    {
        CubicEquation eq({1, 2, 3, 0});
        std::vector<double> expected = {0};
        eq.solve();
        std::vector<double> roots = eq.getRoots();
        ASSERT_EQ(roots, expected);
    }


}