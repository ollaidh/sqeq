#include <gtest/gtest.h>
#include "cbeq.h"

TEST(cbeq, solve) {
    // Q, S variables values define the way to calculate roots, one test for each combination of Q and S
    {
        // S > 0:
        CubicEquation eq({2, -12, 22, -12});
        std::vector<double> expected = {1, 3, 2};
        eq.solve();
        std::vector<double> roots = eq.getRoots();
        ASSERT_EQ(roots.size(), expected.size());
        for (int i = 0; i < roots.size(); i++) {
            // using ASSERT_NEAR here and below as we are comparing doubles and sometimes zeros
            ASSERT_NEAR(roots[i], expected[i], 1e-8);
        }
    }

    {
        // S < 0, Q < 0
        CubicEquation eq({1, 2, 3, 0});
        std::vector<double> expected = {0};
        eq.solve();
        std::vector<double> roots = eq.getRoots();
        ASSERT_EQ(roots.size(), expected.size());
        for (int i = 0; i < roots.size(); i++) {
            ASSERT_NEAR(roots[i], expected[i], 1e-8);
        }
    }

    {
        // S < 0, Q > 0
        CubicEquation eq({1, 2, -3, 1});
        std::vector<double> expected = {-3.07959562349};
        eq.solve();
        std::vector<double> roots = eq.getRoots();
        ASSERT_EQ(roots.size(), expected.size());
        for (int i = 0; i < roots.size(); i++) {
            ASSERT_NEAR(roots[i], expected[i], 1e-8);
        }
    }

    {
        // S < 0, Q == 0
        CubicEquation eq({1, 3, 3, 0});
        std::vector<double> expected = {0};
        eq.solve();
        std::vector<double> roots = eq.getRoots();
        ASSERT_EQ(roots.size(), expected.size());
        for (int i = 0; i < roots.size(); i++) {
            ASSERT_NEAR(roots[i], expected[i], 1e-8);
        }
    }

    {
        // S == 0
        CubicEquation eq({1, 0, -3, 2});
        std::vector<double> expected = {-2, 1};
        eq.solve();
        std::vector<double> roots = eq.getRoots();
        ASSERT_EQ(roots, expected);
        ASSERT_EQ(roots.size(), expected.size());
        for (int i = 0; i < roots.size(); i++) {
            ASSERT_NEAR(roots[i], expected[i], 1e-8);
        }
    }
}